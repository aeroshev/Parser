
class Label;
class Vertex;
class Robot;
class MAIN_CLASS;
class Descriptior_Value;




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
    constant,
    boo
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

        class _Id : public Vertex
        {  
        public:
            std::string name;

            _Id(const std::string& type, const std::string& name):
            Vertex(type),
            name(name)
            {}
        };
        
        class _Value : public Vertex
        {
        public:
            int value;
        

            _Value(const std::string& type, int value):
            Vertex(type),
            value(value)
            {}
        };

        class funcall : public Vertex
        {
        public:
            std::string func_name;
            std::list<std::string> args;

            funcall(const std::string& type, const std::string& func_name, const std::string& decl, const std::list<std::string>& decl_list):
            Vertex(type),
            func_name(func_name),
            args(decl_list)
            {
                args.push_front(decl);
            }

            funcall(const std::string& type, const std::string& func_name, const std::string& decl):
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
            std::list<int> enum_list;

            Appeal(const std::string& type, const std::string& name, const std::list<int>& list):
            Vertex(type),
            name(name),
            enum_list(list)
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
            int literal;
            std::string type;

            std::vector<int> value;

            std::list<int> enum_dim;
            std::vector<uint64_t> shift; 
            
            Descriptior_Value(const std::list<int>& enum_dim, int literal, const std::string& type):
            literal(literal),
            type(type),
            enum_dim(enum_dim)    
            {}

            Descriptior_Value(const std::string& type):
            literal(0),
            type(type)
            {}

            
            Descriptior_Value(const Descriptior_Value& object):
            literal(object.literal),
            type(object.type),
            value(object.value),
            enum_dim(object.enum_dim),
            shift(object.shift)
            {}
            
            Descriptior_Value(const Descriptior_Value& object) = default;
            Descriptior_Value(Descriptior_Value&& object) = delete;
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
        };

class Label
{
public:
	
    Descriptior_Value* id;
    Descriptior_Value* const_id;
    bool flag;
    int constant;
    status marker;

    Label(Descriptior_Value* ptr = nullptr, Descriptior_Value* ptr2 = nullptr, bool flag = false, int const_ = 0):
    id(ptr),
    const_id(ptr2),
    flag(flag),
    constant(const_),
    marker(status::nothing)
    {}

    ~Label()
    {
        if (id != nullptr)
            delete id;
    }	
};

        
class Robot
{
private:
    std::vector<std::vector<uint64_t> > map;
    std::pair<uint64_t, uint64_t> coordinate;
    std::pair<int, int> gaze_direction;

    uint16_t edge_hysteria = 10;
    uint16_t level_hysteria = 0;

    
    static constexpr std::pair<int, int> Down = std::make_pair(0, 1);
    static constexpr std::pair<int, int> Right = std::make_pair(1, 0);
    static constexpr std::pair<int, int> Up = std::make_pair(0, -1);
    static constexpr std::pair<int, int> Left = std::make_pair(-1, 0);

public:
    Robot(const std::pair<uint64_t, uint64_t>& coor, const std::pair<uint64_t, uint64_t>& dir, const std::vector<std::vector<uint64_t> > map_out):
    map(map_out),
    coordinate(coor),
    gaze_direction(dir)
    {}


    Cell move()
    {
        coordinate.first += gaze_direction.first;
        coordinate.second += gaze_direction.second;

        if (map[gaze_direction.first][gaze_direction.second] == Cell::Wall)
        {
            return Cell::Wall;
        }
        if (map[gaze_direction.first][gaze_direction.second] == Cell::Exit)
        {
            return Cell::Exit;
        }

        return Cell::Empty;
    }

    void rotate_left()
    {
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
        Label map;

        int N = 0;//setting this number
        if (level_hysteria < 5)
            N = 5;
        else
            N = 3;

        std::list<int> matrix_dim;
        matrix_dim.push_back(N);
        matrix_dim.push_back(N);
        matrix_dim.push_back(2);

        map.id = new Descriptior_Value(matrix_dim, 1, "INT");

        map.id->shift.push_back(N*N);
        map.id->shift.push_back(N);
        map.id->shift.push_back(1);

        





    }
};

    class MAIN_CLASS final
    {
    private:
        std::map<std::string, Descriptior_func> funcTable;
        std::map<std::string, std::map<std::string, Descriptior_Value*> > idTable;

        std::map<std::string, Descriptior_Value> storageID;

        std::stack<std::string> NameSpace;

        Robot T800;
    public:
        std::list<int> enumeration;
        std::list<std::string> args;


        explicit MAIN_CLASS(const std::pair<uint64_t, uint64_t>& coor, const std::pair<uint64_t, uint64_t>& dir, const std::vector<std::vector<uint64_t> > map_out):
        T800(coor, dir, map_out)
        {
            NameSpace.push("GLOBAL");
        }


        void clear_sys()
        {
            funcTable.clear();

            for (auto& element : idTable)
            {
                element.second.clear();
            }
            idTable.clear();
            enumeration.clear();
            args.clear();

            storageID.clear();
            while(NameSpace.empty())
            {
                NameSpace.pop();
            }
        }



        Vertex* putId(const std::string& name, int literal, const std::string& type)
        {
            storageID.emplace(std::make_pair(std::string(name), Descriptior_Value(enumeration, literal, type)));
            enumeration.clear();

            Vertex * node = new _Id("VAR", name);

            return node;
        }

        // void putFunc(const std::string& name, const std::string& decl, const std::list<std::string>& decl_list, Vertex* stmt, const std::string& end)
        // {
        //     funcTable.emplace(std::make_pair(std::string(name), Descriptior_func(decl, decl_list, stmt, end)));
        // }
        // void putFunc(const std::string& name, const std::string& decl, Vertex* stmt, const std::string& end)
        // {
        //     funcTable.emplace(std::make_pair(std::string(name), Descriptior_func(decl, stmt, end)));
        // }
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

        Vertex* appeal(const std::string& type, const std::string& name)
        {
            Vertex* node = new Appeal(type, name, enumeration);
            enumeration.clear();
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
            Vertex* node = new _Id("ID", name);

            return node;
        }

        Vertex* id_func(const std::string& name)
        {
            Vertex* node = new _Id("FNE", name);

            return node;
        }

        Vertex* constant(int value)
        {
            Vertex* node = new _Value("VALUE", value);

            return node; 
        }

        Vertex* robot(const std::string& name)
        {
            Vertex* node = new Vertex(name);

            return node;
        }

Label execute(Vertex * vertex)
{
        //to do
		// case "ASSIGN"://либо сделать копирующий конструктор и перемещающий
		// {
		// 	Node* asgnNode = static_cast<Node*>(vertex);

  //           Label config_var = execute(asgnNode->leafs[0]);
  //           Label config_expr = execute(asgnNode->leafs[1]);

  //           if (config_var.marker != status::variable)
  //               COMP_ERROR("SOMETHING WRONG! DON'T HAVE VARIABLE");

  //           if (config_var.const_id == nullptr)
  //               COMP_ERROR("SOMETHING WRONG! DON'T HAVE VARIABLE");

  //           if (config_expr.marker == status::temp_variable && config_expr.id != nullptr)
  //           {
  //               config_var.const_id->value.clear();
  //               config_var.const_id->enum_dim.clear();
  //               config_var.const_id->shift.clear();

  //               config_var.const_id->value(config_expr.id->value);
  //               config_var.const_id->enum_dim(config_expr.id->enum_dim);
  //               config_var.const_id->shift(config_expr.id->shift);

  //               config_var.const_id->type = config_expr.id->type;
                
  //               return config;
  //           }
  //           if (config_expr.marker == status::variable && config_expr.const_id != nullptr)
  //           {
  //               config_var.const_id->value.clear();
  //               config_var.const_id->enum_dim.clear();
  //               config_var.const_id->shift.clear();

  //               config_var.const_id->value(config_exp.const_id->value);
  //               config_var.const_id->enum_dim(config_exp.const_id->enum_dim);
  //               config_var.const_id->shift(config_exp.const_id->shift);

  //               config_var.const_id->type = config_exp.const_id->type;

  //               return config; 
  //           }
		
		if (vertex->type == "VAR")//-----------------complete
		{	
			_Id* VarNode= static_cast<_Id*>(vertex);
            std::string name = VarNode->name;
			
			if(idTable[NameSpace.top()].find(name) != idTable[NameSpace.top()].end())
				COMP_ERROR("ID ALREADY DECLARED IN THIS SCOPE");

            auto id = storageID.find(name);

            if (id == storageID.end())
                COMP_ERROR("FATAL ERROR");

            auto result = idTable[NameSpace.top()].insert(std::make_pair(name, &(id->second)));
            if (!result.second)
                COMP_ERROR("FATAL ERROR");

            auto element = id->second;

            size_t dim = 1;
            for (const auto& current : element.enum_dim)
            {
                dim *= current;
            }

            element.value.resize(dim);

            for (const auto& current : element.enum_dim)
            {
                dim /= current;
                element.shift.push_back(dim);
            }

            for (auto& current : element.value)
            {
                current = element.literal;
            }

            Label config;
            return config;
        }
        if (vertex->type == "ID")
        {
            Label config;
            _Id * varNode = static_cast<_Id*>(vertex);

            auto element = idTable[NameSpace.top()].find(varNode->name);
            if (element != idTable[NameSpace.top()].end())
            {
                config.const_id = element->second;
            }
            else
            {
                COMP_ERROR("NOT FOUND ELEMENT");
            }
            config.marker = status::variable;

            return config;
        }
        if (vertex->type == "FNE")
        {
            Label config;
            _Id* varNode = static_cast<_Id*>(vertex);

            auto descriptor = funcTable.find(varNode->name);
            if (descriptor != funcTable.end())
            {
                config.const_id = descriptor->second.result_variable.second;
            }
            else
            {
                COMP_ERROR("NOT FOUND FUNCTION");
            }
            config.marker = status::variable;

            return config;
        }
        if (vertex->type == "VALUE")
        {
            Label config;
            _Value * varNode = static_cast<_Value*>(vertex);

            config.constant = varNode->value;

            config.marker = status::constant;

            return config;
        }
        if (vertex->type == "APPEAL")
        {
            Label config;
            Appeal* apNode = static_cast<Appeal*>(vertex);

            auto element = idTable[NameSpace.top()].find(apNode->name);
            if (element == idTable[NameSpace.top()].end())
                COMP_ERROR("NOT FOUND THIS VARIABLE");

            auto var = element->second;

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
                config.constant = var->value[shift];
                config.marker = status::constant;
            }
            else if (var->type == "BOOL")
            {
                config.flag = var->value[shift];
                config.marker = status::boo;
            }
            else
            {
                COMP_ERROR("UNDEFINE ERROR");
            }

            return config;
        }	
		if (vertex->type == "+")//upgrade to work this simple number
		{	
            Label config;
			Node* plusNode = static_cast<Node*>(vertex);

            Label config_1 = execute(plusNode->leafs[0]);
			Label config_2 = execute(plusNode->leafs[1]);

            Descriptior_Value* ptr1 = nullptr, *ptr2 = nullptr;

            if (config_1.marker == status::constant && config_2.marker == status::constant)
            {
                config.constant = config_1.constant + config_2.constant;

                config.marker = status::constant;
                return config;
            }
            if (config_1.marker == status::boo && config_2.marker == status::boo)
            {
                config.flag = config_1.flag + config_2.flag;

                config.marker = status::boo;
                return config;
            }
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

            for (size_t i = 0; i != sz; i++)
            {
                config.id->value[i] = ptr1->value[i] + ptr2->value[i];
            }

            config.marker = status::temp_variable;
            return config;
        }
		if (vertex->type == "*")
        {   
            Label config;
            Node* plusNode = static_cast<Node*>(vertex);

            Label config_1 = execute(plusNode->leafs[0]);
            Label config_2 = execute(plusNode->leafs[1]);

            Descriptior_Value* ptr1 = nullptr, *ptr2 = nullptr;

            if (config_1.marker == status::constant && config_2.marker == status::constant)
            {
                config.constant = config_1.constant * config_2.constant;

                config.marker = status::constant;
                return config;
            }
            if (config_1.marker == status::boo && config_2.marker == status::boo)
            {
                config.flag = config_1.flag * config_2.flag;

                config.marker = status::boo;
                return config;
            }
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

            for (size_t i = 0; i != sz; i++)
            {
                config.id->value[i] = ptr1->value[i] * ptr2->value[i];
            }

            config.marker = status::temp_variable;
            return config;
        }
        if (vertex->type == "-")
        {   
            Label config;
            Node* plusNode = static_cast<Node*>(vertex);

            Label config_1 = execute(plusNode->leafs[0]);
            Label config_2 = execute(plusNode->leafs[1]);

            Descriptior_Value* ptr1 = nullptr, *ptr2 = nullptr;

            if (config_1.marker == status::constant && config_2.marker == status::constant)
            {
                config.constant = config_1.constant - config_2.constant;

                config.marker = status::constant;
                return config;
            }
            if (config_1.marker == status::boo && config_2.marker == status::boo)
            {
                config.flag = config_1.flag - config_2.flag;

                config.marker = status::boo;
                return config;
            }
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

            for (size_t i = 0; i != sz; i++)
            {
                config.id->value[i] = ptr1->value[i] - ptr2->value[i];
            }

            config.marker = status::temp_variable;
            return config;
        }
        if (vertex->type == "/")
        {   
            Label config;
            Node* plusNode = static_cast<Node*>(vertex);

            Label config_1 = execute(plusNode->leafs[0]);
            Label config_2 = execute(plusNode->leafs[1]);

            Descriptior_Value* ptr1 = nullptr, *ptr2 = nullptr;

            if (config_1.marker == status::constant && config_2.marker == status::constant)
            {
                config.constant = config_1.constant / config_2.constant;

                config.marker = status::constant;
                return config;
            }
            if (config_1.marker == status::boo && config_2.marker == status::boo)
            {
                config.flag = config_1.flag / config_2.flag;

                config.marker = status::boo;
                return config;
            }
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

            for (size_t i = 0; i != sz; i++)
            {
                config.id->value[i] = ptr1->value[i] / ptr2->value[i];
            }

            config.marker = status::temp_variable;
            return config;
        }			
		if (vertex->type == "MXCOMP")//
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
                COMP_ERROR("DOESN't MATCH THIS TYPE");

            size_t quantity = 0;
            size_t sz = ptr->value.size();

            for (size_t i = 0; i != sz; i++)
            {
                if (ptr->value[i] == 0)
                    quantity++;
            }

            if (quantity > sz - quantity)
                config.flag = "true";
            else
                config.flag = "false";

            config.marker = status::boo;
            return config;	
        }
        if (vertex->type == "ELCOMP")//
        {
            Node* compNode = static_cast<Node*>(vertex);

            Label config = execute(compNode->leafs[0]);

            if (config.marker == status::constant)
            {
                if (config.constant == 0)
                {
                    config.flag = "true";
                }
                else
                {
                    config.flag = "false";
                }
                config.marker = status::boo;
            }

            return config;
        }
		if (vertex->type == "NOT")
		{
            Label temp_config;					
			Node* notNode = static_cast<Node*>(vertex);

            Label config = execute(notNode->leafs[0]);

            if (config.marker == status::boo)
            {
                temp_config.flag = not config.flag;

                temp_config.marker = status::boo;
                return temp_config;
            }

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

            for (size_t i = 0; i != sz; i++)
            {
                temp_config.id->value[i] = not ptr->value[i];
            }

            temp_config.marker = status::temp_variable;
            return temp_config;	
        }
		if (vertex->type == "AND")
		{
            Label config;
            Node* andNode = static_cast<Node*>(vertex);

            Label config_1 = execute(andNode->leafs[0]);
			Label config_2 = execute(andNode->leafs[1]);

            if (config_1.marker == status::boo && config_2.marker == status::boo)
            {
                config.flag = config_1.flag and config_2.flag;

                config.marker = status::boo;
                return config;
            }

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

            for (size_t i = 0; i != sz; i++)
            {
                config.id->value[i] = ptr1->value[i] and ptr2->value[i];
            }

            config.marker = status::temp_variable;
            return config;
        }	
		if (vertex->type == "MXTRUE")
        {
            Label temp_config;
            Node* mxNode = static_cast<Node*>(vertex);
			
			Label config = execute(mxNode->leafs[0]);

            if (config.marker == status::boo)
            {
                temp_config.flag = config.flag;

                temp_config.marker = status::boo;
                return temp_config;
            }

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

            if (quantity > sz - quantity)
                temp_config.flag = "true";
            else
                temp_config.flag = "false";

            temp_config.marker = status::boo;
            return temp_config;  
        }
        if (vertex->type == "MXFALSE")
        {
            Label temp_config;
            Node* mxNode = static_cast<Node*>(vertex);
            
            Label config = execute(mxNode->leafs[0]);

            if (config.marker == status::boo)
            {
                temp_config.flag = not config.flag;

                temp_config.marker = status::boo;
                return temp_config;
            }

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

            if (quantity > sz - quantity)
                temp_config.flag = "true";
            else
                temp_config.flag = "false";

            temp_config.marker = status::boo;
            return temp_config;  
        }
		if (vertex->type == "FOR")//?
		{	
            Node* forNode = static_cast<Node*>(vertex);

            Label config_counter = execute(forNode->leafs[0]);
            Label config_edge = execute(forNode->leafs[1]);
            Label config_step = execute(forNode->leafs[2]);
            

            if (config_counter.const_id->type != "INT")
                COMP_ERROR("NE TOT TIP");
            if (config_edge.const_id->type != "INT")
                COMP_ERROR("NE TOT TIP");
            if (config_step.const_id->type != "INT")
                COMP_ERROR("NE TOT TIP");

            auto iter_counter = config_counter.const_id->enum_dim.begin();
            auto end_counter = config_counter.const_id->enum_dim.end();

            auto iter_edge = config_edge.const_id->enum_dim.begin();
            auto end_edge = config_edge.const_id->enum_dim.end();

            auto iter_step = config_step.const_id->enum_dim.begin();
            auto end_step = config_step.const_id->enum_dim.end();


            while(iter_counter != end_counter || iter_step != end_step || iter_edge != end_edge)
            {
                if (*iter_counter == *iter_step)
                {
                    if(*iter_step == *iter_edge)
                    {
                        iter_counter++;
                        iter_step++;
                        iter_edge++;
                        continue;
                    }
                    else
                    {
                        COMP_ERROR("NOT EQUAL SIZE VARIABLE");
                    }
                }
                else
                {
                    COMP_ERROR("NOT EQUAL SIZE VARIABLE");
                }
            }
            if (iter_counter != end_counter || iter_step != end_step || iter_edge != end_edge)
                COMP_ERROR("NOT EQUAL SIZE VARIABLE");

            size_t sz = config_step.const_id->value.size();
            size_t quantity = 0;
            int sign = 0;

            Descriptior_Value* ptr_counter = config_counter.const_id;
            Descriptior_Value* ptr_edge = config_edge.const_id;
            Descriptior_Value* ptr_step = config_step.const_id;

            while(1)
            {
                for (size_t i = 0; i != sz; i++)
                {

                }
                if (quantity == sz)
                    break;

                execute(forNode->leafs[3]);

                quantity = 0;


            }

            Label config;
            return config;
		}
        if (vertex->type == "SWITCH")
        {
            Label config;
            Node* swNode = static_cast<Node*>(vertex);

            Label config_logic_expr = execute(swNode->leafs[0]);
            Label config_bool_1 = execute(swNode->leafs[1]);
            Label config_bool_2 = execute(swNode->leafs[3]);

            if (config_logic_expr.marker != status::boo)
                COMP_ERROR("DON'T HAVE RESULT");

            if (config_logic_expr.flag == config_bool_1.flag)
                config = execute(swNode->leafs[2]);
            if (config_logic_expr.flag == config_bool_2.flag)
                config = execute(swNode->leafs[4]);

            return config;
        }
		if (vertex->type == "DO")
		{	
            funcall* callNode = static_cast<funcall*>(vertex);

            auto element_func = funcTable.find(callNode->func_name);
            if (element_func == funcTable.end())
                COMP_ERROR("NOT FOUND NAME FUNCTION");

            for (const auto& argument : callNode->args)
            {
                if (idTable[NameSpace.top()].find(argument) == idTable[NameSpace.top()].end())
                    COMP_ERROR("NOT FOUND VARIABLE");
            }



            NameSpace.push(callNode->func_name);


            for (const auto& argument : callNode->args)
            {
                auto store_el = storageID.find(argument);
                auto result = idTable[NameSpace.top()].insert(std::make_pair(argument, &store_el->second));
                if (!result.second)
                    COMP_ERROR("ERROR INSERTING ELEMENT");
            }


            execute(element_func->second.body);


            auto res_variable = idTable[NameSpace.top()].find(element_func->second.result_variable.first);
            if (res_variable == idTable[NameSpace.top()].end())
                COMP_ERROR("NOT FOUND RESULT VARIABLE");

            element_func->second.result_variable.second = res_variable->second;


            NameSpace.pop();


            Label config;
            return config;
		}
        if (vertex->type == "GET")
        {
            Node* getNode = static_cast<Node*>(vertex);

            Label config = execute(getNode->leafs[0]);

            return config;
        }
        if (vertex->type == "SIZE")
        {
            Node* szNode = static_cast<Node*>(vertex);

            Label config_var = execute(szNode->leafs[0]);

            if (config_var.const_id == nullptr || config_var.marker != status::variable)
                COMP_ERROR("DONT'T HAVE VALUE");

            Label config;
            config.constant = config_var.const_id->enum_dim.size();

            config.marker = status::constant;

            return config;
        }
        if (vertex->type == "LOGITIZE")
        {
            Node* loeNode = static_cast<Node*>(vertex);

            Label config_var = execute(loeNode->leafs[0]);

            if (config_var.const_id == nullptr || config_var.marker != status::variable)
                COMP_ERROR("DONT'T HAVE VALUE");

            if (config_var.const_id->type == "BOOL")
                return config_var;

            for (auto& current : config_var.const_id->value)
            {
                if (current == 0)
                    current = 0;
                else
                    current = 1;
            }

            config_var.const_id->type = "BOOL";

            return config_var;
        }
        if (vertex->type == "DIGITIZE")
        {
            Node* digNode = static_cast<Node*>(vertex);

            Label config_var = execute(digNode->leafs[0]);

            if (config_var.const_id == nullptr || config_var.marker != status::variable)
                COMP_ERROR("DONT'T HAVE VALUE");

            if (config_var.const_id->type == "INT")
                return config_var;

            for (auto& current : config_var.const_id->value)
            {
                if (current == 0)
                    current = 0;
                else
                    current = 1;
            }

            config_var.const_id->type = "INT";

            return config_var;
        }
        if (vertex->type == "REDUCE")
        {
            Node* rNode = static_cast<Node*>(vertex);

            Label config;
            Label config_var = execute(rNode->leafs[0]);
            Label config_const = execute(rNode->leafs[1]);

            if (config_const.constant >= config_var.const_id->enum_dim.size())
                COMP_ERROR("NOT THIS OPERATION");

            config.id = new Descriptior_Value(*config_var.const_id);
            config.marker = status::temp_variable;

            for (size_t i = 0; i != config_const.constant; i++)
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
        if (vertex->type == "EXTENED")
        {
            Node* rNode = static_cast<Node*>(vertex);

            Label config;
            Label config_var = execute(rNode->leafs[0]);
            Label config_const = execute(rNode->leafs[1]);

            if (config_const.constant < 1)
                COMP_ERROR("NOT THIS OPERATION");

            config.id = new Descriptior_Value(*config_var.const_id);
            config.marker = status::temp_variable;


            config.id->enum_dim.push_back(config_const.constant);

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
        if (vertex->type == "MOVE")
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
        if (vertex->type == "ROTATE_LEFT")
        {
            T800.rotate_left();

            Label config;
            return config;
        }
        if (vertex->type == "ROTATE_RIGHT")
        {
            T800.rotate_right();

            Label config;
            return config;
        }
        if (vertex->type == "GET_E")
        {
            Label config = T800.get_environment();

            return config;
        }
        if (vertex->type == "UMINUS")
        {
            Node* uNode = static_cast<Node*>(vertex);

            Label config = execute(uNode->leafs[0]);

            if (config.marker == status::constant)
            {
                config.constant = -config.constant;
                return config;
            }
            if (config.marker == status::variable)
            {
                for (auto& element : config.const_id->value)
                {
                    element = -element;
                }
            }
            if (config.marker == status::temp_variable)
            {
                for (auto& element : config.id->value)
                {
                    element = -element;
                }
            }

            return config;
        }
        if (vertex->type == "ENDLINE")
        {
            Node* stmtNode = static_cast<Node*>(vertex);

            if (stmtNode->leafs[0])
                execute(stmtNode->leafs[0]);
            if (stmtNode->leafs[1])
                execute(stmtNode->leafs[1]);

            Label config;
            return config;
        }      
}
};