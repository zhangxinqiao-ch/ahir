#ifndef _VC_ROOT_H_
#define _VC_ROOT_H_

#include <vcIncludes.hpp>
// language keywords (all start with $)

enum vcLexerKeytags
  {
    __ATTRIBUTE = 0    	,
    __DPE           ,
    __LIBRARY       ,
    __MEMORYSPACE   	,
    __UNORDERED   	,
    __OBJECT        ,
    __CAPACITY      	,
    __DATAWIDTH     	,
    __ADDRWIDTH     	,
    __MAXACCESSWIDTH     	,
    __MODULE        ,
    __FOREIGN        ,
    __PIPELINE        ,
    __OPERATOR        ,
    __VOLATILE        ,
    __SERIESBLOCK   	,
    __PARALLELBLOCK 	,
    __FORKBLOCK     	,
    __PIPELINEDFORKBLOCK,
    __BRANCHBLOCK   	,
    __LOOPBLOCK,
    __OF            	,
    __FORK          	,
    __JOIN          	,
    __MARKEDJOIN          	,
    __BRANCH          	,
    __MERGE         	,
    __ENTRY         	,
    __EXIT          	,
    __N_ULL          	,
    __IN            	,
    __OUT           	,
    __REQS          	,
    __ACKS          	,
    __TRANSITION    		,
    __PLACE         	,
    __HIDDEN        	,
    __COLON	    	, // label separator
    __COMMA        	, // argument-separator, index-separator etc.
    __ASSIGNEQUAL   	, // assignment
    __LESS          	, // less-than
    __GREATER       	, // greater-than
    __IMPLIES       	, 
    __EQUIVALENT        ,
    __LBRACE        	, // scope open
    __RBRACE        	, // scope close
    __LBRACKET      	, // array index marker
    __RBRACKET      	, // array index marker
    __LPAREN        	, // argument-list
    __RPAREN        	, // argument-list
    __SLASH             ,
    __INT           		,
    __FLOAT         		,
    __POINTER       		,
    __ARRAY         	,
    __RECORD        ,
    __PARAMETER    ,
    __PORT ,
    __MAP,
    __DATAPATH,
    __CONTROLPATH,
    __WIRE,
    __MIN,
    __MAX,
    __DPEINSTANCE,
    __LINK,
    __PHI,
    __LOAD,
    __STORE,
    __TO,
    __CALL,
    __INLINE,
    __IOPORT,
    __PIPE,
    __LIFO,
    __NOBLOCK,
    __SIGNAL,
    __P2P,
    __FROM,
    __AT,
    __CONSTANT,
    __INTERMEDIATE,
    __DEPTH,
    __BUFFERING,
    __GUARD,
    __BIND,
    __TERMINATE,
    __PHISEQUENCER,
    __TRANSITIONMERGE,
    __PLUS_OP          , 
    __MINUS_OP         , 
    __MUL_OP           , 
    __DIV_OP           , 
    __SHL_OP           , 
    __SHR_OP           , 
    __ROL_OP           , 
    __ROR_OP           , 
    __SGT_OP            , 
    __SGE_OP            , 
    __EQ_OP            , 
    __SLT_OP            , 
    __SLE_OP            , 
    __UGT_OP           ,
    __UGE_OP           ,
    __ULT_OP           ,
    __ULE_OP           ,
    __NEQ_OP           , 
    __UNORDERED_OP    ,
    __BITSEL_OP        , 
    __CONCAT_OP        , 
    __BRANCH_OP        , 
    __SELECT_OP       ,
    __SLICE_OP       ,
    __ASSIGN_OP           ,
    __NOT_OP           ,
    __OR_OP            ,
    __AND_OP           ,
    __XOR_OP           ,
    __NOR_OP           ,
    __NAND_OP          ,
    __XNOR_OP          ,
    __EQUIVALENCE_OP,
    __PERMUTE_OP,
    __OPEN,
    __DELAY,
    __SHRA_OP,
    __UtoS_ASSIGN_OP , 
    __StoS_ASSIGN_OP , 
    __StoU_ASSIGN_OP ,
    __FtoS_ASSIGN_OP,
    __FtoU_ASSIGN_OP ,
    __StoF_ASSIGN_OP ,
    __UtoF_ASSIGN_OP ,
    __FtoF_ASSIGN_OP ,
    __DEAD,
    __TIED_HIGH,
    __LEFT_OPEN,
    __HASH
  };

static string vcLexerKeywords[] = 
  {   "$attribute"		,
      "$dpe"		,
      "$lib"		,
      "$memoryspace"		,
      "$unordered"		,
      "$object"		,
      "$capacity"		,
      "$datawidth"		,
      "$addrwidth"		,
      "$maxaccesswidth"		,
      "$module"		,
      "$foreign"		,
      "$pipeline"		,
      "$operator"		,
      "$volatile"		,
      ";;"		, // series block
      "||"		, // parallel block
      "::"		, // fork-join block
      ":|:"		, // pipelined-fork-join block
      "<>"		, // branch-merge block
      "<o>"		, // simple-loop block
      "$of"		,
      "&->"		,
      "<-&"		,
      "o<-&"		,
      "|->"		,
      "<-|"		,
      "$entry"		,
      "$exit"		,
      "$null"		,
      "$in"		,
      "$out"		,
      "$reqs"		,
      "$acks"		,
      "$T"		,
      "$P"		,
      "$hidden"		,
      ":" 		, // label separator
      "," 		, // argument-separator, index-separator etc.
      ":=" 		, // assignment
      "<" 		, // less-than
      ">" 		, // greater-than
      "=>"		, // implies
      "<=>"             ,
      "{" 		, // scope open
      "}" 		, // scope close
      "[" 		, // array index marker
      "]" 		, // array index marker
      "(" 		, // argument-list
      ")" 		, // argument-list
      "/"               ,
      "$int"     		,
      "$float"   		,
      "$pointer" 		,
      "$array"		,
      "$record",
      "$parameter",
      "$port",
      "$map",
      "$DP",
      "$CP",
      "$W",
      "$min",
      "$max",
      "$dpeinstance",
      "$link",
      "$phi",
      "$load",
      "$store",
      "$to",
      "$call",
      "$inline",
      "$ioport",
      "$pipe",
      "$lifo",
      "$noblock",
      "$signal",
      "$p2p",
      "$from",
      "$at",
      "$constant",
      "$intermediate",
      "$depth",
      "$buffering",
      "$guard",
      "$bind",
      "$terminate",
      "$phisequencer",
      "$transitionmerge",
      "+",
      "-",
      "*",
      "/",
      "<<",
      ">>",
      "<o<",
      ">o>",
      "$S>$S",
      "$S>=$S",
      "==",
      "$S<$S",
      "$S<=$S",
      ">",
      ">=",
      "<",
      "<=",
      "!=",
      "><", // unordered op.
      "[]",
      "&&",
      "==0?",
      "?",
      "[:]",
      ":=",
      "~",
      "|",
      "&",
      "^",
      "~|",
      "~&",
      "~^",
      "&/",
      ":X=",
      "$open",
      "$delay",
      // signed shr
      "$S>>",
      // type-conversions
      // int <-> int 
      "$S:=$U", 
      "$S:=$S", 
      "$U:=$S",
      // int <-> float
      "$S:=$F",
      "$U:=$F",
      "$F:=$S",
      "$F:=$U",
      "$F:=$F",
      "$dead",
      "$tied_high",
      "$left_open",
      "#"
  };

string To_VHDL(string x);
string IntToStr(unsigned int x);
string Int64ToStr(int64_t x);
string StripBracketingQuotes(string x);
int CeilLog2(int n);
int Log(int n, int base); // log n to base 2, rounded down to int.
int IPow(int n, int e); 

#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x < y ? x : y)

class vcRoot
{
protected:
  string _id;
  map<string,string> _attribute_map;

  int64_t _root_index;

  static int64_t _root_index_counter;
 public:
  vcRoot();
  vcRoot(string id);

  virtual void Add_Attribute(string tag, string value);

  bool Has_Attribute(string tag);
  string Find_Attribute_Value(string tag);

  string Get_Id();
  virtual string Get_VHDL_Id() {return(To_VHDL(this->Get_Id()));}

  string Get_Label();

  virtual void Print(ostream& ofile);

  int64_t Get_Root_Index() {return(_root_index);}


  virtual void Print(ofstream& ofile);
  virtual void Print(string& ostring);
  virtual string To_String() {string ret_string; this->Print(ret_string); return(ret_string);}

  virtual string Kind()
  {
    return("vcRoot");
  }

  bool Is(string class_name)
  {
    return(class_name == this->Kind());
  }

  void Print_Attributes(ostream& ofile);

  virtual void Print_VHDL(ostream& ofile) {assert(0);}
  void Print_VHDL(ofstream& ofile);

};

//  compare functor
struct vcRoot_Compare:public binary_function
  <vcRoot*, vcRoot*, bool >
{
  bool operator() (vcRoot*, vcRoot*) const;
};

// misc. functions.
int max(vector<int>& vec);
int min(vector<int>& vec);


void Print_VHDL_Join(string join_name,
		     vector<string>& preds,
		     vector<int>& pred_markings,
		     vector<int>& pred_capacities,
		     vector<int>& pred_delays,
		     string joined_symbol,
		     ostream& ofile);

void Print_VHDL_Simple_Join(string join_name, 
			    vector<string>& pred_symbols, 
			    string joined_symbol,
			    int delay,
			    ostream& ofile);

#endif // vcRoot
