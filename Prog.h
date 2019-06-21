#pragma once

#include <string>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>

void COMP_ERROR(const char*);

enum Cell
{
    Empty,
    Wall,
    Exit
};


enum status
{
    nothing,
    variable,
    temp_variable,
};

class Vertex
{
public:
    std::string type;
    
    Vertex(const std::string& name):
    type(name)
    {}
    
    virtual ~Vertex(){}
};

class Id : public Vertex
{
public:
    std::string name;
    
    Id(const std::string& type, const std::string& name):
    Vertex(type),
    name(name)
    {}
};

class Value : public Vertex
{
public:
    int value;
    std::string type_value;
    
    
    Value(const std::string& type, int value, const std::string& type_value):
    Vertex(type),
    value(value),
    type_value(type_value)
    {}
};

class Funcall : public Vertex
{
public:
    std::string func_name;
    std::list<std::string> args;
    
    Funcall(const std::string& type, const std::string& func_name, const std::string& decl, const std::list<std::string>& decl_list):
    Vertex(type),
    func_name(func_name),
    args(decl_list)
    {
        args.push_front(decl);
    }
    
    Funcall(const std::string& type, const std::string& func_name, const std::string& decl):
    Vertex(type),
    func_name(func_name)
    {
        args.push_front(decl);
    }
};

class Appeal : public Vertex
{
public:
    std::string name;

    std::list<Vertex*> expr_list;
    std::list<int> enum_list;
    
    Appeal(const std::string& type, const std::string& name, const std::list<Vertex*>& list):
    Vertex(type),
    name(name),
    expr_list(list)
    {}
};

class Node : public Vertex
{
public:
    unsigned int count_leaf;
    std::vector<Vertex *> leafs;
    
    Node(const std::string& type, int count_leaf, const std::vector<Vertex *> vec):
    Vertex(type),
    count_leaf(count_leaf),
    leafs(vec)
    {}
};


class Descriptior_Value
{
public:
    std::string name;
    int literal;
    std::string type;
    
    std::vector<int> value;
    
    std::list<int> enum_dim;
    std::vector<uint64_t> shift;

    std::list<Vertex*> expr_dim;
    
    Descriptior_Value(const std::string& name, const std::list<Vertex*>& expr_dim, int literal, const std::string& type):
    name(name),
    literal(literal),
    type(type),
    expr_dim(expr_dim)
    {}
    
    Descriptior_Value(const std::string& type):
    name(""),
    literal(0),
    type(type)
    {}
    

    Descriptior_Value(const Descriptior_Value& object) = default;
    Descriptior_Value(Descriptior_Value&& object) = default;
};

class Descriptior_func
{
public:
    Vertex* body;
    std::pair<std::string, Descriptior_Value*> result_variable;
    
    std::list<std::string> args;
    
    Descriptior_func(const std::string& decl, const std::list<std::string>& decl_list, Vertex* stmt_, const std::string& end):
    body(stmt_),
    result_variable(std::make_pair(end, nullptr)),
    args(decl_list)
    {
        args.push_front(decl);
    }
    
    Descriptior_func(const std::string& decl, Vertex* stmt_, const std::string& end):
    body(stmt_),
    result_variable(std::make_pair(end, nullptr))
    {
        args.push_front(decl);
    }

    Descriptior_func(Vertex* stmt):
    body(stmt)
    {}
};

class Label
{
public:
    Descriptior_Value* id;
    Descriptior_Value* const_id;

    status marker;
    
    Label(Descriptior_Value* ptr = nullptr, Descriptior_Value* ptr2 = nullptr):
    id(ptr),
    const_id(ptr2),
    marker(status::nothing)
    {}

    Label(const std::string& type)
    {
        const_id = nullptr;

        id = new Descriptior_Value(type);
        marker = status::temp_variable;

        id->shift.push_back(1);
        id->enum_dim.push_back(1);
    }
    
    ~Label()
    {
        if (id != nullptr)
        {
            delete id;
        }
    }
};


class Robot
{
private:
    std::pair<uint64_t, uint64_t> coordinate;
    std::pair<int, int> gaze_direction;

    uint64_t rows;
    uint64_t columns;

    uint16_t edge_hysteria = 10;
    uint16_t level_hysteria = 0;

    uint16_t courtesy = 0;
    uint16_t edge_courtesy = 4;
    
    static constexpr std::pair<int, int> Down = std::make_pair(1, 0);
    static constexpr std::pair<int, int> Right = std::make_pair(0, 1);
    static constexpr std::pair<int, int> Up = std::make_pair(-1, 0);
    static constexpr std::pair<int, int> Left = std::make_pair(0, -1);

    std::vector<std::vector<uint64_t> > map;
    
public:

    Robot(const std::pair<uint64_t, uint64_t>& coor, const std::pair<uint64_t, uint64_t>& dir, const std::vector<std::vector<uint64_t> >& map_out):  
    coordinate(coor),
    gaze_direction(dir),
    map(map_out)
    {
        rows = map_out.size();
        columns = map_out[0].size();
    }

    void civility(int count)
    {
        courtesy += count;
    }

    void check_hysteria()
    {
        if (courtesy < edge_courtesy)
        {
            if (level_hysteria > courtesy) 
                level_hysteria -= courtesy;
            if (level_hysteria != 0)
                level_hysteria--;

        }
        else
        {
            level_hysteria++;
        }

        if (level_hysteria >= edge_hysteria)
            COMP_ERROR("I DON'T LIKE YOU!");
    }
    
    
    Cell move()
    {
        coordinate.first += gaze_direction.first;
        coordinate.second += gaze_direction.second;


        if (map[coordinate.first][coordinate.second] == Cell::Wall)
        {
            return Cell::Wall;
        }
        if (map[coordinate.first][coordinate.second] == Cell::Exit)
        {
            return Cell::Exit;
        }
        
        return Cell::Empty;
    }
    
    void rotate_left()
    {
        level_hysteria++;
        if (gaze_direction.first == Down.first && gaze_direction.second == Down.second)
        {
            gaze_direction.first = Right.first;
            gaze_direction.second = Right.second;
            return;
        }
        if (gaze_direction.first == Right.first && gaze_direction.second == Right.second)
        {
            gaze_direction.first = Up.first;
            gaze_direction.second = Up.second;
            return;
        }
        if (gaze_direction.first == Up.first && gaze_direction.second == Up.second)
        {
            gaze_direction.first = Left.first;
            gaze_direction.second = Left.second;
            return;
        }
        if (gaze_direction.first == Left.first && gaze_direction.second == Left.second)
        {
            gaze_direction.first = Down.first;
            gaze_direction.second = Down.second;
            return;
        }
    }
    void rotate_right()
    {
        level_hysteria++;
        if (gaze_direction.first == Down.first && gaze_direction.second == Down.second)
        {
            gaze_direction.first = Left.first;
            gaze_direction.second = Left.second;
            return;
        }
        if (gaze_direction.first == Left.first && gaze_direction.second == Left.second)
        {
            gaze_direction.first = Up.first;
            gaze_direction.second = Up.second;
            return;
        }
        if (gaze_direction.first == Up.first && gaze_direction.second == Up.second)
        {
            gaze_direction.first = Right.first;
            gaze_direction.second = Right.second;
            return;
        }
        if (gaze_direction.first == Right.first && gaze_direction.second == Right.second)
        {
            gaze_direction.first = Down.first;
            gaze_direction.second = Down.second;
            return;
        }
    }
    
    Label get_environment()
    {
        level_hysteria++;
        Label field;
        
        int N = 5;
        if (level_hysteria < 7)
            N = 5;
        else
            N = 3;
     
        
        field.id = new Descriptior_Value("INT");
        field.id->name = "field";

        field.id->literal = 0;

        field.id->enum_dim.push_back(2);
        field.id->enum_dim.push_back(N);
        field.id->enum_dim.push_back(N);
        
        field.id->shift.push_back(N*N);
        field.id->shift.push_back(N);
        field.id->shift.push_back(1);

        size_t sz = (N * N) * 2;
        field.id->value.resize(sz);

        for (size_t i = 0; i != sz; i++)
        {
            field.id->value[i] = 0;
        }
        size_t line = N;
        N = (N - 1) / 2;

  

        size_t i = coordinate.first;
        unsigned int count_up = 0;
        while (count_up != N && i != 0)
        {
            i--;
            count_up++;
        }

        i = coordinate.first;
        unsigned int count_down = 0;
        while (count_down != N && i != rows - 1)
        {
            i++;
            count_down++;
        }

        i = coordinate.second;
        unsigned int count_left = 0;
        while (count_left != N && i != 0)
        {
            i--;
            count_left++;
        }

        i = coordinate.second;
        unsigned int count_right = 0;
        while (count_right != N && i != columns - 1)
        {
            i++;
            count_right++;
        }


        std::pair<size_t, size_t> scan = std::make_pair(coordinate.first - count_up, coordinate.second - count_left);
        size_t walls = (N - count_up) * line + (N - count_left);
        size_t doors = field.id->shift.front() + ((N - count_up) * line) + (N - count_left);


        size_t length_horizont = count_left + count_right + 1;
        size_t length_vertical = count_up + count_down + 1;




        for (size_t i = 0; i != length_vertical; i++)
        {
            for (size_t j = 0; j != length_horizont; j++)
            {
 
                if (map[scan.first][scan.second] == Cell::Wall)
                {

                    field.id->value[walls] = 1;
                }
                if (map[scan.first][scan.second] == Cell::Exit)
                {
                    field.id->value[doors] = 2;
                    level_hysteria--;
                }
                walls++;
                doors++;

                scan.second++;
            }


            scan.second = coordinate.second - count_left;
            scan.first++;
            walls += (N - count_left) + (N - count_right);
            doors += (N - count_left) + (N - count_right);

        }

        //PRINT_IN_COUT----------------------------------------------
        for (size_t i = 0; i != rows; i++)
        {
            for (size_t j = 0; j != columns; j++)
            {
                if (coordinate.first == i && coordinate.second == j)
                    std::cout << "R" << ' ';
                else
                    std::cout << map[i][j] << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
        //---------------------------------------------------------



        //PRINT_IN_FILE--------------------------------------------
        std::ofstream file("output.txt");
        for (int i = 0; i != line * line; i += line)
        {
            for (int j = 0; j != line; j++)
            {
                file << field.id->value[i + j] << ' ';
            }
            file << '\n';
        }
        file << '\n';
        
        for (int i = field.id->shift.front(); i != field.id->value.size( ); i += line)
        {
            for (int j = 0; j != line; j++)
            {
                file << field.id->value[i + j] << ' ';
            }
            file << '\n';
        }
        //---------------------------------------------------------

        return field;   
    }
};

class MAIN_CLASS final
{
private:
    std::map<std::string, Descriptior_func> funcTable;
    std::map<std::string, std::map<std::string, Descriptior_Value*> > idTable;
    
    std::list<Descriptior_Value> storageID;
    
    std::stack<std::string> NameSpace;
    
    Robot T800;
    
public:
    std::list<std::string> args;
    std::list<Vertex*> exprl;
    
    
    explicit MAIN_CLASS(const std::pair<uint64_t, uint64_t>& coor, const std::pair<uint64_t, uint64_t>& dir, const std::vector<std::vector<uint64_t> >& map_out):
    T800(coor, dir, map_out)
    {
        NameSpace.push("GLOBAL");
    }

    Vertex* courtesy(int count, Vertex* stmt)
    {
        T800.civility(count);
        return stmt;
    }
    
    
    void clear_sys()
    {
        funcTable.clear();
        
        for (auto& element : idTable)
        {
            element.second.clear();
        }
        idTable.clear();
        args.clear();
        exprl.clear();
        
        storageID.clear();
        while(!NameSpace.empty())
        {
            NameSpace.pop();
        }
    }
    
    
    
    Vertex* putId(const std::string& name, int literal, const std::string& type)
    {

        storageID.emplace_back(Descriptior_Value(name, exprl, literal, type));
        exprl.clear();
        
        Vertex * node = new Id("VAR", name);
        
        return node;
    }

    void putFunc(const std::string& name, const std::string& decl, Vertex* stmt, const std::string& end)
    {
        if (!args.empty())
        {
            funcTable.emplace(std::make_pair(std::string(name), Descriptior_func(decl, args, stmt, end)));
            args.clear();
        }
        else
            funcTable.emplace(std::make_pair(std::string(name), Descriptior_func(decl, stmt, end)));
    }

    void putFunc(Vertex* stmt)
    {
        funcTable.emplace(std::make_pair(std::string("FINDEXIT"), Descriptior_func(stmt)));
    }
    
    Vertex* appeal(const std::string& type, const std::string& name)
    {
        Vertex* node = new Appeal(type, name, exprl);
        exprl.clear();
        return node;
    }

    Vertex* funcall(const std::string& type, const std::string& func_name, const std::string& decl, const std::list<std::string>& decl_list)
    {
        Vertex* node = new Funcall(type, func_name, decl, decl_list);

        return node;
    }

    Vertex* funcall(const std::string& type, const std::string& func_name, const std::string& decl)
    {
        Vertex* node = new Funcall(type, func_name, decl);

        return node;
    }
    
    Vertex* create(const std::string& type, int count, ...)
    {
        std::vector<Vertex *> leafs;
        va_list vl;
        
        va_start(vl, count);
        
        for (int i = 0; i < count; i++)
        {
            Vertex* ptr = va_arg(vl, Vertex*);
            leafs.push_back(ptr);
        }
        
        Vertex* node;
        node = new Node(type, count, leafs);
        va_end (vl);
        
        return node;
    }
    
    Vertex* id(const std::string& name)
    {
        Vertex* node = new Id("ID", name);
        
        return node;
    }
    
    Vertex* id_func(const std::string& name)
    {
        Vertex* node = new Id("FNE", name);
        
        return node;
    }
    
    Vertex* constant(int value, const std::string& type)
    {
        Vertex* node = new Value("VALUE", value, type);
        
        return node;
    }
    
    Vertex* robot(const std::string& name)
    {
        Vertex* node = new Vertex(name);
        
        return node;
    }

    void check_main(Vertex* vertex)
    {
        auto element = funcTable.find("FINDEXIT");
        if (element != funcTable.end())
            execute(vertex);
        else
            COMP_ERROR("NOT FOUND FINDEXIT");
    }
    
    Label execute(Vertex* vertex)
    {
        T800.check_hysteria();


        if (vertex->type == "PRINT")//return notfing
        {
            Node* pNode = static_cast<Node*>(vertex);

            Label config_var = execute(pNode->leafs[0]);


            Descriptior_Value* ptr = nullptr;

            if (config_var.id == nullptr)
                if(config_var.const_id == nullptr)
                    COMP_ERROR("ERROR");
                else
                    ptr = config_var.const_id;
            else
                ptr = config_var.id;


            std::cout << "------------------------------------" << '\n';

            for (size_t i = 0; i != ptr->value.size(); i++)
            {
                std::cout <<  ptr->value[i] << '\t';
            }
            std::cout << '\n' << "------------------------------------" << '\n';

            Label config;
            return config;
        }
        if (vertex->type == "ASSIGN")//return nothing
        {
            Node* asgnNode = static_cast<Node*>(vertex);
            Label config;

            Label config_var = execute(asgnNode->leafs[0]);
            Label config_expr = execute(asgnNode->leafs[1]);
            
            if (config_var.marker != status::variable || config_var.const_id == nullptr)
              COMP_ERROR("SOMETHING WRONG! DON'T HAVE VARIABLE");

            if (config_expr.marker == status::temp_variable && config_expr.id != nullptr)
            {
                config_var.const_id->value.clear();
                config_var.const_id->enum_dim.clear();
                config_var.const_id->shift.clear();
                    
                config_var.const_id->value.swap(config_expr.id->value);
                config_var.const_id->enum_dim.swap(config_expr.id->enum_dim);
                config_var.const_id->shift.swap(config_expr.id->shift);
        
                config_var.const_id->type = config_expr.id->type;
        
                return config;
            }
            if (config_expr.marker == status::variable && config_expr.const_id != nullptr)
            {
                if (config_var.const_id->name == config_expr.const_id->name)
                    return config;


                config_var.const_id->value.clear();
                config_var.const_id->enum_dim.clear();
                config_var.const_id->shift.clear();
                   

                std::copy(config_expr.const_id->value.begin(), config_expr.const_id->value.end(), std::back_inserter(config_var.const_id->value));
                std::copy(config_expr.const_id->enum_dim.begin(), config_expr.const_id->enum_dim.end(), std::back_inserter(config_var.const_id->enum_dim));
                std::copy(config_expr.const_id->shift.begin(), config_expr.const_id->shift.end(), std::back_inserter(config_var.const_id->shift));

        
                config_var.const_id->type = config_expr.const_id->type;
        
                return config;
            }

            return config;
        }
        
        if (vertex->type == "VAR")//return nothing
        {  
            Id* VarNode= static_cast<Id*>(vertex);
            std::string name = VarNode->name;
            
           
            
            if(idTable[NameSpace.top()].find(name) != idTable[NameSpace.top()].end())
                COMP_ERROR("ID ALREADY DECLARED IN THIS SCOPE");
            
            
            //Search this in storage
            auto element = storageID.begin();
            while(element != storageID.end())
            {
                if (element->name == name)
                    break;
                element++;
            }
            //Check
            if (element == storageID.end())
                COMP_ERROR("FATAL ERROR");


            //Calculate size variable
            size_t dim = 1;

            Descriptior_Value* ptr_expr = nullptr;

            if (!element->expr_dim.empty())
            {
                for (const auto& current : element->expr_dim)
                {
                    Label config_expr = execute(current);

                    if (config_expr.id == nullptr)
                        if (config_expr.const_id == nullptr)
                            COMP_ERROR("ERROR");
                        else
                        ptr_expr = config_expr.const_id;
                    else
                        ptr_expr = config_expr.id;

                    if (ptr_expr->value.size() > 1)
                        COMP_ERROR("this is not a simple number");

                    if (ptr_expr->value[0] < 1)
                        COMP_ERROR("invalid value index");

                    element->enum_dim.push_back(ptr_expr->value[0]);

                    dim *= ptr_expr->value[0];
                }
            }


            element->expr_dim.clear();

            
            element->value.resize(dim);

            //Fiil container
            for (auto& current : element->value)
            {
                current = element->literal;
            }

            
            //Fill shigt field
            for (const auto& current : element->enum_dim)
            {
                dim /= current;
                element->shift.push_back(dim);
            }



            Descriptior_Value* ptr = &(*element);
            auto result = idTable[NameSpace.top()].insert(std::make_pair(name, ptr));
            if (!result.second)
                COMP_ERROR("FATAL ERROR");

            
            Label config;
            return config;
        }
        if (vertex->type == "ID")//return reference of value
        {
            Label config;
            Id* varNode = static_cast<Id*>(vertex);
            
            auto element = idTable[NameSpace.top()].find(varNode->name);
            if (element != idTable[NameSpace.top()].end())
            {
                config.const_id = element->second;
                config.marker = status::variable;
            }
            else
            {
                COMP_ERROR("NOT FOUND ELEMENT");
            }
                  
            return config;
        }
        if (vertex->type == "FNE")//return reference of value
        {
            Label config;
            Id* varNode = static_cast<Id*>(vertex);
            
            auto descriptor = funcTable.find(varNode->name);
            if (descriptor != funcTable.end())
            {
                if (descriptor->second.result_variable.second != nullptr)
                    config.const_id = descriptor->second.result_variable.second;

                config.marker = status::variable;
            }
            else
            {
                COMP_ERROR("NOT FOUND FUNCTION");
            }
            
            
            return config;
        }
        if (vertex->type == "VALUE")//return temp value
        {
            Value* varNode = static_cast<Value*>(vertex);

            Label config(varNode->type_value);
            config.id->value.push_back(varNode->value);

            return config;
        }
        if (vertex->type == "APPEAL")//return temp value
        {
            Appeal* apNode = static_cast<Appeal*>(vertex);
            
            auto element = idTable[NameSpace.top()].find(apNode->name);
            if (element == idTable[NameSpace.top()].end())
                COMP_ERROR("NOT FOUND THIS VARIABLE");
            
            auto var = element->second;
          

            Descriptior_Value* ptr_expr = nullptr;
            if (!apNode->expr_list.empty())
            {
                apNode->enum_list.clear();

                for (const auto& current : apNode->expr_list)
                {
                    Label config_expr = execute(current);

                    if (config_expr.id == nullptr)
                        if (config_expr.const_id == nullptr)
                            COMP_ERROR("ERROR");
                        else
                        ptr_expr = config_expr.const_id;
                    else
                        ptr_expr = config_expr.id;

                    if (ptr_expr->value.size() > 1)
                        COMP_ERROR("this is not a simple number");

                    if (ptr_expr->value[0] < 1)
                        COMP_ERROR("invalid value index");

                    apNode->enum_list.push_back(ptr_expr->value[0]);
                }
            }

            if (apNode->enum_list.size() > var->enum_dim.size())
                COMP_ERROR("too many meanings");
            
            
            size_t shift = 0;
            size_t sz = apNode->enum_list.size();
            
            auto appeal_iter = apNode->enum_list.begin();
            auto var_iter = var->enum_dim.begin();
            auto var_shift = var->shift.begin();
            
            for (size_t i = 0; i != sz; i++)
            {
                if (*appeal_iter > *var_iter || *appeal_iter < 1)
                    COMP_ERROR("OVERTAKE SIZE INDEX");
                
                shift += (*appeal_iter - 1)*(*var_shift);
                
                appeal_iter++;
                var_iter++;
                var_shift++;
            }
            

            if (var->type == "INT")
            {

                Label config("INT");
                config.id->value.push_back(var->value[shift]);

                return config;
            }
            else if (var->type == "BOOL")
            {

                Label config("BOOL");
                config.id->value.push_back(var->value[shift]);

                return config;
            }
            else
            {
                COMP_ERROR("UNDEFINE ERROR");
            }
            
            Label config_;
            return config_;
        }
        if (vertex->type == "APPEAL_A")//return temp variable //upgrade check 
        {
            Appeal* apNode = static_cast<Appeal*>(vertex);
            
            auto element = idTable[NameSpace.top()].find(apNode->name);
            if (element == idTable[NameSpace.top()].end())
                COMP_ERROR("NOT FOUND THIS VARIABLE");
            
            auto var = element->second;
            
            

            Descriptior_Value* ptr_expr = nullptr;
            if (!apNode->expr_list.empty())
            {
                for (const auto& current : apNode->expr_list)
                {
                    Label config_expr = execute(current);

                    if (config_expr.id == nullptr)
                        if (config_expr.const_id == nullptr)
                            COMP_ERROR("ERROR");
                        else
                        ptr_expr = config_expr.const_id;
                    else
                        ptr_expr = config_expr.id;

                    if (ptr_expr->value.size() > 1)
                        COMP_ERROR("this is not a simple number");

                    if (ptr_expr->value[0] < 1)
                        COMP_ERROR("invalid value index");

                    apNode->enum_list.push_back(ptr_expr->value[0]);
                }
            }


            if (apNode->enum_list.size() > var->enum_dim.size())
                COMP_ERROR("too many meanings");
            
            
            size_t shift = 0;
            size_t sz = apNode->enum_list.size();
            
            auto appeal_iter = apNode->enum_list.begin();
            auto var_iter = var->enum_dim.begin();
            auto var_shift = var->shift.begin();
            
            for (size_t i = 0; i != sz; i++)
            {
                if (*appeal_iter > *var_iter || *appeal_iter < 1)
                    COMP_ERROR("OVERTAKE SIZE INDEX");
                
                shift += (*appeal_iter - 1)*(*var_shift);
                
                appeal_iter++;
                var_iter++;
                var_shift++;
            }

            Label config("INT");
            config.id->value.push_back(shift);
            config.id->name = apNode->name;

            return config;
        }
        if (vertex->type == "ASSIGN_A")//return nothing
        {
            Node* asgNode = static_cast<Node*>(vertex);

            Label config_var = execute(asgNode->leafs[0]);
            Label config_expr = execute(asgNode->leafs[1]);

            if (config_var.id == nullptr || config_var.marker != status::temp_variable)
                COMP_ERROR("TAKE A BAD ADRESS");

            if (config_var.id->value.size() > 1)
                COMP_ERROR("DO NOT SIMPLE NUMBER");

            if (config_expr.id == nullptr || config_expr.marker != status::temp_variable)
                COMP_ERROR("TAKE A BAD EXPRESSION");

            if (config_expr.id->value.size() > 1)
                COMP_ERROR("DO NOT SIMPLE NUMBER");

            auto element = idTable[NameSpace.top()].find(config_var.id->name);
            if (element == idTable[NameSpace.top()].end())
                COMP_ERROR("NOT FOUND THIS VARIABLE");

            auto var = element->second;

            var->value[config_var.id->value[0]] = config_expr.id->value[0];

            Label config;
            return config;
        }
        if (vertex->type == "+")
        {

            Label config;
            Node* plusNode = static_cast<Node*>(vertex);
            
            Label config_1 = execute(plusNode->leafs[0]);
            Label config_2 = execute(plusNode->leafs[1]);
            
            Descriptior_Value* ptr1 = nullptr, *ptr2 = nullptr;
            

            if (config_1.id == nullptr)
                if(config_1.const_id == nullptr)
                    COMP_ERROR("ERROR");
                else
                    ptr1 = config_1.const_id;
                else
                    ptr1 = config_1.id;
            
            if (config_2.id == nullptr)
                if(config_2.const_id == nullptr)
                    COMP_ERROR("ERROR");
                else
                    ptr2 = config_2.const_id;
                else
                    ptr2 = config_2.id;
            
            
            if (ptr1->type != ptr2->type)
                COMP_ERROR("NOT EQUAL TYPE");
            //one more match enum?
            if (ptr1->value.size() != ptr2->value.size())
                COMP_ERROR("NOT EQUAL SIZE");
            
            
            size_t sz = ptr1->value.size();
            config.id = new Descriptior_Value(ptr1->type);
            config.id->value.resize(sz);
            
            if (ptr1->type == "INT")
            {
                for (size_t i = 0; i != sz; i++)
                {
                    config.id->value[i] = ptr1->value[i] + ptr2->value[i];
                }
            }
            if (ptr1->type == "BOOL")
            {
                for (size_t i = 0; i != sz; i++)
                {
                    if (ptr1->value[i] == 1)
                        config.id->value[i] = 1;
                    else if (ptr2->value[i] == 1)
                        config.id->value[i] = 1;
                    else
                        config.id->value[i] = 0;
                }
            }
            
            config.marker = status::temp_variable;
            return config;
        }
        if (vertex->type == "*")//return temp variable
        {
            Label config;
            Node* plusNode = static_cast<Node*>(vertex);
            
            Label config_1 = execute(plusNode->leafs[0]);
            Label config_2 = execute(plusNode->leafs[1]);
            
            Descriptior_Value* ptr1 = nullptr, *ptr2 = nullptr;

            if (config_1.id == nullptr)
                if(config_1.const_id == nullptr)
                    COMP_ERROR("ERROR_1");
                else
                    ptr1 = config_1.const_id;
            else
                ptr1 = config_1.id;
            
            if (config_2.id == nullptr)
                if(config_2.const_id == nullptr)
                    COMP_ERROR("ERROR_2");
                else
                    ptr2 = config_2.const_id;
                else
                    ptr2 = config_2.id;
            
            
            if (ptr1->type != ptr2->type)
                COMP_ERROR("NOT EQUAL TYPE");
            //one more match enum?
            if (ptr1->value.size() != ptr2->value.size())
                COMP_ERROR("NOT EQUAL SIZE");
            
            
            size_t sz = ptr1->value.size();
            config.id = new Descriptior_Value(ptr1->type);
            config.id->value.resize(sz);
            
            for (size_t i = 0; i != sz; i++)
            {
                config.id->value[i] = ptr1->value[i] * ptr2->value[i];
                std::cout << config.id->value[i] << '\n';
            }


            
            config.marker = status::temp_variable;
            return config;
        }
        if (vertex->type == "-")//return temp variable
        {
            Label config;
            Node* plusNode = static_cast<Node*>(vertex);
            
            Label config_1 = execute(plusNode->leafs[0]);
            Label config_2 = execute(plusNode->leafs[1]);
            
            Descriptior_Value* ptr1 = nullptr, *ptr2 = nullptr;
            

            if (config_1.id == nullptr)
                if(config_1.const_id == nullptr)
                    COMP_ERROR("ERROR");
                else
                    ptr1 = config_1.const_id;
                else
                    ptr1 = config_1.id;
            
            if (config_2.id == nullptr)
                if(config_2.const_id == nullptr)
                    COMP_ERROR("ERROR");
                else
                    ptr2 = config_2.const_id;
                else
                    ptr2 = config_2.id;
            
            
            if (ptr1->type != ptr2->type)
                COMP_ERROR("NOT EQUAL TYPE");
            //one more match enum?
            if (ptr1->value.size() != ptr2->value.size())
                COMP_ERROR("NOT EQUAL SIZE");
            
            
            size_t sz = ptr1->value.size();
            config.id = new Descriptior_Value(ptr1->type);
            config.id->value.resize(sz);
            
            for (size_t i = 0; i != sz; i++)
            {
                config.id->value[i] = ptr1->value[i] - ptr2->value[i];
            }
            
            config.marker = status::temp_variable;
            return config;
        }
        if (vertex->type == "/")//return temp variable
        {
            Label config;
            Node* plusNode = static_cast<Node*>(vertex);
            
            Label config_1 = execute(plusNode->leafs[0]);
            Label config_2 = execute(plusNode->leafs[1]);
            
            Descriptior_Value* ptr1 = nullptr, *ptr2 = nullptr;
            

            if (config_1.id == nullptr)
                if(config_1.const_id == nullptr)
                    COMP_ERROR("ERROR");
                else
                    ptr1 = config_1.const_id;
                else
                    ptr1 = config_1.id;
            
            if (config_2.id == nullptr)
                if(config_2.const_id == nullptr)
                    COMP_ERROR("ERROR");
                else
                    ptr2 = config_2.const_id;
                else
                    ptr2 = config_2.id;
            
            
            if (ptr1->type != ptr2->type)
                COMP_ERROR("NOT EQUAL TYPE");
            //one more match enum?
            if (ptr1->value.size() != ptr2->value.size())
                COMP_ERROR("NOT EQUAL SIZE");
            
            
            size_t sz = ptr1->value.size();
            config.id = new Descriptior_Value(ptr1->type);
            config.id->value.resize(sz);
            
            for (size_t i = 0; i != sz; i++)
            {
                config.id->value[i] = ptr1->value[i] / ptr2->value[i];
            }
            
            config.marker = status::temp_variable;
            return config;
        }
        if (vertex->type == "MXCOMP")//return temp variable
        {
            Node* compNode = static_cast<Node*>(vertex);
            
            Label config = execute(compNode->leafs[0]);
            
            Descriptior_Value* ptr = nullptr;
            
            if (config.id == nullptr)
                if (config.const_id == nullptr)
                    COMP_ERROR("DON'T HAVE VARIABLE");
                else
                    ptr = config.const_id;
                else
                    ptr = config.id;
            
            if (ptr->type != "INT")
                COMP_ERROR("DOESN'T MATCH THIS TYPE");
            
            size_t quantity = 0;
            size_t sz = ptr->value.size();
            
            for (size_t i = 0; i != sz; i++)
            {
                if (ptr->value[i] == 0)
                    quantity++;
            }

            Label config_res;
            config_res.id = new Descriptior_Value("BOOL");
            config_res.id->shift.push_back(1);

            config_res.marker = status::temp_variable;

            
            if (quantity > sz - quantity)
                config_res.id->value.push_back(1);
            else
                config_res.id->value.push_back(0);

            return config_res;
        }
        if (vertex->type == "ELCOMP")//return temp variable
        {
            Node* compNode = static_cast<Node*>(vertex);
            
            Label config = execute(compNode->leafs[0]);
            Label config_res("BOOL");

            if (config.marker == status::temp_variable && config.id->value.size() == 1)
            {
                if (config.id->value[0] == 0)
                {
                    config_res.id->shift.push_back(1);
                }
                else
                {
                    config_res.id->shift.push_back(0);
                }
            }
            else
            {
                std::cout << "It's not single number" << '\n';
            }

            
            return config_res;
        }
        if (vertex->type == "NOT")//return temp variable
        {
            Label temp_config;
            Node* notNode = static_cast<Node*>(vertex);
            
            Label config = execute(notNode->leafs[0]);

            
            Descriptior_Value* ptr = nullptr;
            
            if (config.id == nullptr)
                if (config.const_id == nullptr)
                    COMP_ERROR("DON'T HAVE VARIABLE");
                else
                    ptr = config.const_id;
                else
                    ptr = config.id;
            
            if (ptr->type != "BOOL")
                COMP_ERROR("CAN'T MATCH NOT BOOL");
            
            size_t sz = ptr->value.size();
            temp_config.id = new Descriptior_Value(ptr->type);
            temp_config.id->value.resize(sz);
            
            for (size_t i = 0; i != sz; i++)
            {
                if (ptr->value[i] == 0)
                    temp_config.id->value[i] = 1;
                else
                    temp_config.id->value[i] = 0;
            }
            
            temp_config.marker = status::temp_variable;
            return temp_config;
        }
        if (vertex->type == "AND")//return temp variable
        {
            Label config;
            Node* andNode = static_cast<Node*>(vertex);
            
            Label config_1 = execute(andNode->leafs[0]);
            Label config_2 = execute(andNode->leafs[1]);
            
            
            Descriptior_Value* ptr1 = nullptr, *ptr2 = nullptr;
            
            
            if (config_1.id == nullptr)
                if(config_1.const_id == nullptr)
                    COMP_ERROR("ERROR");
                else
                    ptr1 = config_1.const_id;
                else
                    ptr1 = config_1.id;
            
            if (config_2.id == nullptr)
                if(config_2.const_id == nullptr)
                    COMP_ERROR("ERROR");
                else
                    ptr2 = config_2.const_id;
                else
                    ptr2 = config_2.id;
            
            if (ptr1->type != "BOOL" || ptr2->type != "BOOL")
                COMP_ERROR("CAN'T MATCH NOT BOOL");
            
            if (ptr1->value.size() != ptr2->value.size())
                COMP_ERROR("NOT EQUAL SIZE");
            
            size_t sz = ptr1->value.size();
            config.id = new Descriptior_Value(ptr1->type);
            config.id->value.resize(sz);
            
            for (size_t i = 0; i != sz; i++)
            {
                if (ptr1->value[i] == 0)
                    config.id->value[i] = 0;
                else if (ptr2->value[i] == 0)
                    config.id->value[i] = 0;
                else
                    config.id->value[i] = 1;
            }
            
            config.marker = status::temp_variable;
            return config;
        }
        if (vertex->type == "MXTRUE")//return temp variable
        {           
            Node* mxNode = static_cast<Node*>(vertex);
            
            Label config = execute(mxNode->leafs[0]);
            
            Descriptior_Value* ptr = nullptr;
            
            if (config.id == nullptr)
                if (config.const_id == nullptr)
                    COMP_ERROR("DON'T HAVE VARIABLE");
                else
                    ptr = config.const_id;
                else
                    ptr = config.id;
            
            if (ptr->type != "BOOL")
                COMP_ERROR("CAN'T MATCH NOT BOOL");
            
            size_t sz = ptr->value.size();
            size_t quantity = 0;
            
            for (size_t i = 0; i != sz; i++)
            {
                if (ptr->value[i] == 1)
                    quantity++;
            }

            Label temp_config;
            temp_config.id = new Descriptior_Value("BOOL");
            temp_config.id->shift.push_back(1);
            temp_config.marker = status::temp_variable;

            if (quantity > sz - quantity)
            {
                temp_config.id->value.push_back(1);
            }
            else
            {
                temp_config.id->value.push_back(0);
            }

            return temp_config;
        }
        if (vertex->type == "MXFALSE")//return temp variable
        {
            Node* mxNode = static_cast<Node*>(vertex);
            
            Label config = execute(mxNode->leafs[0]);
            
            
            Descriptior_Value* ptr = nullptr;
            
            if (config.id == nullptr)
                if (config.const_id == nullptr)
                    COMP_ERROR("DON'T HAVE VARIABLE");
                else
                    ptr = config.const_id;
                else
                    ptr = config.id;
            
            if (ptr->type != "BOOL")
                COMP_ERROR("CAN'T MATCH NOT BOOL");
            
            size_t sz = ptr->value.size();
            size_t quantity = 0;
            
            for (size_t i = 0; i != sz; i++)
            {
                if (ptr->value[i] == 0)
                    quantity++;
            }
            

            Label temp_config;
            temp_config.id = new Descriptior_Value("BOOL");
            temp_config.id->shift.push_back(1);
            temp_config.marker = status::temp_variable;

            if (quantity > sz - quantity)
            {
                temp_config.id->value.push_back(1);
            }
            else
            {
                temp_config.id->value.push_back(0);
            }

            return temp_config;
        }
        if (vertex->type == "FOR")//return notfing
        {

            Node* forNode = static_cast<Node*>(vertex);
            
            Label config_counter = execute(forNode->leafs[0]);
            Label config_edge = execute(forNode->leafs[1]);
            Label config_step = execute(forNode->leafs[2]);
            
            Descriptior_Value* counter = config_counter.const_id;
            Descriptior_Value* edge = config_edge.const_id;
            Descriptior_Value* step = config_step.const_id;


            if (counter->type != "INT")
                COMP_ERROR("NE TOT TIP");
            if (edge->type != "INT")
                COMP_ERROR("NE TOT TIP");
            if (step->type != "INT")
                COMP_ERROR("NE TOT TIP");

            if (counter->value.size() != edge->value.size())
                COMP_ERROR("NOT EQUAL SIZE");
            if (edge->value.size() != step->value.size())
                COMP_ERROR("NOT EQUAL SIZE");


            int forward = 0;
            size_t sz = counter->value.size();
            for(size_t i = 0; i != sz; i++)
            {
                if (counter->value[i] + step->value[i] > counter->value[i])
                    forward = 1;
                else if (counter->value[i] + step->value[i] < counter->value[i])
                    forward = -1;
                else
                    forward = 0;

                if (forward == 1)
                {
                    while (counter->value[i] < edge->value[i])
                    {
                        counter->value[i] += step->value[i];
                        execute(forNode->leafs[3]);
                    }
                    continue;
                }
                if (forward == -1)
                {
                    while (counter->value[i] > edge->value[i])
                    {
                        counter->value[i] += step->value[i];
                        execute(forNode->leafs[3]);
                    }
                    continue;
                }
                if (forward == 0)
                {
                    while(true)
                    {
                        execute(forNode->leafs[3]);
                    }
                }
            }
            
            Label config;
            return config;
        }
        if (vertex->type == "SWITCH")//return nothing
        {
            Node* swNode = static_cast<Node*>(vertex);
            
            Label config_logic_expr = execute(swNode->leafs[0]);
            Label config_bool_1 = execute(swNode->leafs[1]);
            Label config_bool_2 = execute(swNode->leafs[3]);


            Descriptior_Value* ptr = nullptr;
            
            if (config_logic_expr.id == nullptr)
                if (config_logic_expr.const_id == nullptr)
                    COMP_ERROR("DON'T HAVE VARIABLE");
                else
                    ptr = config_logic_expr.const_id;
                else
                    ptr = config_logic_expr.id;

            if (ptr->value.size() != 1)
                COMP_ERROR("REQUIRED SINGLE RESULT");
            
            if (ptr->value[0] == config_bool_1.id->value[0])
                execute(swNode->leafs[2]);
            if (ptr->value[0] == config_bool_2.id->value[0])
                execute(swNode->leafs[4]);

            Label config;
            return config;
        }
        if (vertex->type == "DO")//return nothing
        {
            std::cout << "DO" << '\n';
            
            Funcall* callNode = static_cast<Funcall*>(vertex);
            
            auto element_func = funcTable.find(callNode->func_name);
            if (element_func == funcTable.end())
                COMP_ERROR("NOT FOUND NAME FUNCTION");


            
            for (const auto& argument : callNode->args)
            {
                std::cout << "DO: ARGS " << argument << '\n';
                if (idTable[NameSpace.top()].find(argument) == idTable[NameSpace.top()].end())
                    COMP_ERROR("NOT FOUND VARIABLE");
            }
            
            
            
            NameSpace.push(callNode->func_name);
            
            
            for (const auto& argument : callNode->args)
            {
                auto element = storageID.begin();
                while(element != storageID.end())
                {
                    if (element->name == argument)
                        break;
                    element++;
                }
                Descriptior_Value* ptr = &(*element);
                auto result = idTable[NameSpace.top()].insert(std::make_pair(argument, ptr));
                if (!result.second)
                    COMP_ERROR("ERROR INSERTING ELEMENT");
            }
            
            
            execute(element_func->second.body);
            

            //--------------------------------
            bool flag = false;
            auto args_list_func = element_func->second.args;
            size_t i = 0;
            for (auto iter_args = args_list_func.begin(); iter_args != args_list_func.end(); iter_args++)
            {
                if (*iter_args == element_func->second.result_variable.first)
                {
                    flag = true;
                    break;
                }
                i++;
            }
            if (flag)
            {
                auto iter_call= callNode->args.begin();
                for(; i != 0; i--)
                {
                    iter_call++;
                }
                element_func->second.result_variable.first = *iter_call;
            }
            //---------------------------------------

            auto res_variable = idTable[NameSpace.top()].find(element_func->second.result_variable.first);
            if (res_variable == idTable[NameSpace.top()].end())
                COMP_ERROR("NOT FOUND RESULT VARIABLE");
            
            element_func->second.result_variable.second = res_variable->second;
            
            
            NameSpace.pop();
            
            
            Label config;
            return config;
        }
        if (vertex->type == "GET")//return result of function
        {
            Node* getNode = static_cast<Node*>(vertex);
            
            Label config = execute(getNode->leafs[0]);

            if (config.const_id == nullptr)
                std::cerr << "Function hasn't executed yet" << '\n';
            
            return config;
        }
        if (vertex->type == "SIZE")//return tenp variable
        {
            Node* szNode = static_cast<Node*>(vertex);
            
            Label config_var = execute(szNode->leafs[0]);
            
            if (config_var.const_id == nullptr || config_var.marker != status::variable)
                COMP_ERROR("DONT'T HAVE VALUE");
            

            Label config("INT");

            config.id->value.push_back(config_var.const_id->value.size());

            
            return config;
        }
        if (vertex->type == "DIGITIZE")//return nothing
        {
            Node* digNode = static_cast<Node*>(vertex);
            
            Label config_var = execute(digNode->leafs[0]);
            
            if (config_var.const_id == nullptr || config_var.marker != status::variable)
                COMP_ERROR("DONT'T HAVE VALUE");
            
            if (config_var.const_id->type == "INT")
            {
                std::cout << "It has is already INT" << '\n';
                return config_var;
            }
            
            for (auto& current : config_var.const_id->value)
            {
                if (current == 0)
                    current = 0;
                else
                    current = 1;
            }
            
            config_var.const_id->type = "INT";
            
            Label config;
            return config;
        }
        if (vertex->type == "LOGITIZE")//return nothing
        {
            Node* loeNode = static_cast<Node*>(vertex);
            
            Label config_var = execute(loeNode->leafs[0]);
            
            if (config_var.marker != status::variable)
                COMP_ERROR("DONT'T HAVE VALUE");
            if (config_var.const_id == nullptr)
                COMP_ERROR("DONT'T HAVE VALUE");
            
            if (config_var.const_id->type == "BOOL")
            {
                std::cout << "THIS IS ALREADY BOOL" << '\n';
                return config_var;
            }


            for (auto& current : config_var.const_id->value)
            {
                if (current == 0)
                    current = 0;
                else
                    current = 1;
            }
            
            config_var.const_id->type = "BOOL";


            Label config;
            return config;
        }
        if (vertex->type == "REDUCE")//add check variable of empty
        {
            Node* rNode = static_cast<Node*>(vertex);
            
            Label config;
            Label config_var = execute(rNode->leafs[0]);
            Label config_const = execute(rNode->leafs[1]);
            
            if (config_const.id->value[0] >= config_var.const_id->enum_dim.size())
                COMP_ERROR("NOT THIS OPERATION");
            
            config.id = new Descriptior_Value(*config_var.const_id);
            config.marker = status::temp_variable;
            
            for (size_t i = 0; i != config_const.id->value[0]; i++)
            {
                config.id->enum_dim.pop_back();
            }
            
            size_t sz = 1;
            for (const auto& cur_dim : config.id->enum_dim)
            {
                sz *= cur_dim;
            }
            
            config.id->value.resize(sz);
            
            config.id->shift.clear();
            for (const auto& cur_dim : config.id->enum_dim)
            {
                sz /= cur_dim;
                config.id->shift.push_back(sz);
            }
            
            return config;
        }
        if (vertex->type == "EXTENED")//add check variable of empty
        {
            Node* rNode = static_cast<Node*>(vertex);
            
            Label config;
            Label config_var = execute(rNode->leafs[0]);
            Label config_const = execute(rNode->leafs[1]);
            
            if (config_const.id->value[0] < 1)
                COMP_ERROR("NOT THIS OPERATION");
            
            config.id = new Descriptior_Value(*config_var.const_id);
            config.marker = status::temp_variable;
            
            
            config.id->enum_dim.push_back(config_const.id->value[0]);
            
            size_t sz = 1;
            for (const auto& cur_dim : config.id->enum_dim)
            {
                sz *= cur_dim;
            }
            
            
            config.id->value.resize(sz);
            
            config.id->shift.clear();
            for (const auto& cur_dim : config.id->enum_dim)
            {
                sz /= cur_dim;
                config.id->shift.push_back(sz);
            }
            
            return config;
        }
        if (vertex->type == "MOVE")//return nothing
        {
            Cell status = T800.move();
            
            if (status == Cell::Wall)
            {
                COMP_ERROR("you wanna kill me?");
            }
            if (status == Cell::Exit)
            {
                std::cout << "Execellent i find exit, stupid piece of meat" << '\n';
                clear_sys();
                exit(0);
            }
            
            Label config;
            return config;
        }
        if (vertex->type == "ROTATE_LEFT")//return nothing
        {
            T800.rotate_left();
            
            Label config;
            return config;
        }
        if (vertex->type == "ROTATE_RIGHT")//return nothing
        {
            T800.rotate_right();
            
            Label config;
            return config;
        }
        if (vertex->type == "GET_E")//return temp variable
        {
            Label config = T800.get_environment();
            config.marker = status::temp_variable;
            
            return config;
        }
        if (vertex->type == "UMINUS")//retrun variable or temp variable
        {
            Node* uNode = static_cast<Node*>(vertex);
            
            Label config = execute(uNode->leafs[0]);

            if (config.marker == status::temp_variable)
            {
                for (auto& element : config.id->value)
                {
                    element = -element;
                }
            }
            if (config.marker == status::variable)
            {
                for (auto& element : config.const_id->value)
                {
                    element = -element;
                }
            }
            
            return config;
        }
        if (vertex->type == "ENDLINE")//return nothing
        {
            Node* stmtNode = static_cast<Node*>(vertex);
            
            if (stmtNode->leafs[0])
                execute(stmtNode->leafs[0]);
        
            if (stmtNode->leafs[1])
                execute(stmtNode->leafs[1]);
 
            Label config;
            return config;
        }
        
        Label uni_config;
        return uni_config;
    }
    
};