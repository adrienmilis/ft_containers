#include <iostream>
#include <sys/time.h>

#if STL==1
    #include <map>
    namespace ft=std;

#else
    #include "../map.hpp"
    #include "../utils.hpp"

#endif

void test_map_cppcom()
{
    std::cout << "******STARTING TO TEST ft::map******" << std::endl;
    
    std::cout << "----------INSERT-----------" << std::endl;
    {
    	ft::map<char,int> mymap;

        // first insert function version (single parameter):
        mymap.insert ( ft::pair<char,int>('a',100) );
        mymap.insert ( ft::pair<char,int>('z',200) );

        ft::pair<ft::map<char,int>::iterator,bool> ret;
        ret = mymap.insert ( ft::pair<char,int>('z',500) );
        if (ret.second==false) {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret.first->second << '\n';
        }
        ft::map<char, int>::iterator it = mymap.begin();
        mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
        mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

        // third insert function version (range insertion):
        ft::map<char,int> anothermap;
        anothermap.insert(mymap.begin(), mymap.find('c'));

        // showing contents:
        std::cout << "mymap contains:\n";
        for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
        std::cout << "anothermap contains:\n";
        for (it=anothermap.begin(); it!=anothermap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    }

    std::cout << "----------OPERATOR[]-----------" << std::endl;
    {
        ft::map<char,std::string> mymap;

        mymap['a']="an element";
        mymap['b']="another element";
        mymap['c']=mymap['b'];

        std::cout << "mymap['a'] is " << mymap['a'] << '\n';
        std::cout << "mymap['b'] is " << mymap['b'] << '\n';
        std::cout << "mymap['c'] is " << mymap['c'] << '\n';
        std::cout << "mymap['d'] is " << mymap['d'] << '\n';

        std::cout << "mymap now contains " << mymap.size() << " elements.\n";

    }

    std::cout << "----------SIZE-----------" << std::endl;
    {  
    	ft::map<char,int> mymap;
        mymap['a']=101;
        mymap['b']=202;
        mymap['c']=302;

        std::cout << "mymap.size() is " << mymap.size() << '\n';
    }

    std::cout << "----------EMPTY-----------" << std::endl;
    {
    	ft::map<char,int> mymap;

        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;

        while (!mymap.empty())
        {
          std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
          mymap.erase(mymap.begin());
        }
    }
    
    std::cout << "----------SWAP-----------" << std::endl;
     {
    	ft::map<char,int> foo,bar;

        foo['x']=100;
        foo['y']=200;

        bar['a']=11;
        bar['b']=22;
        bar['c']=33;

        foo.swap(bar);

        std::cout << "foo contains:\n";
        for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';

        std::cout << "bar contains:\n";
        for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';

     }

    
    std::cout << "----------ERASE-----------" << std::endl;
    {  
        ft::map<char,int> mymap;
        ft::map<char,int>::iterator it;

        // insert some values:
        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;
        mymap['d']=40;
        mymap['e']=50;
        mymap['f']=60;

        it=mymap.find('b');
        mymap.erase (it);                   // erasing by iterator

        mymap.erase ('c');                  // erasing by key

        it=mymap.find ('e');
        mymap.erase ( it, mymap.end() );    // erasing by range

        // show content:
        for (it=mymap.begin(); it!=mymap.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';
    }
    
    std::cout << "----------KEY__COMP-----------" << std::endl;
    {
        ft::map<char,int> mymap;

        ft::map<char,int>::key_compare mycomp = mymap.key_comp();

        mymap['a']=100;
        mymap['b']=200;
        mymap['c']=300;

        std::cout << "mymap contains:\n";

        char highest = mymap.rbegin()->first;     // key value of last element

        ft::map<char,int>::iterator it = mymap.begin();
        do {
          std::cout << it->first << " => " << it->second << '\n';
        } while ( mycomp((*it++).first, highest) );

        std::cout << '\n';
    }
    
    
    std::cout << "----------VALUE__COMP-----------" << std::endl;
    {
    	ft::map<char,int> mymap;

        mymap['x']=1001;
        mymap['y']=2002;
        mymap['z']=3003;

        std::cout << "mymap contains:\n";

        ft::pair<char,int> highest = *mymap.rbegin();          // last element

        ft::map<char,int>::iterator it = mymap.begin();
        do {
          std::cout << it->first << " => " << it->second << '\n';
        } while ( mymap.value_comp()(*it++, highest) );

    }
    
    std::cout << "----------COUNT-----------" << std::endl;
     {
    	ft::map<char,int> mymap;
        char c;

        mymap ['a']=101;
        mymap ['c']=202;
        mymap ['f']=303;

        for (c='a'; c<'h'; c++)
        {
          std::cout << c;
          if (mymap.count(c)>0)
            std::cout << " is an element of mymap.\n";
          else 
            std::cout << " is not an element of mymap.\n";
        }
     }
    
    std::cout << "----------LOWER__BOUND-----------" << std::endl;
    {
    	ft::map<char,int> mymap;
        ft::map<char,int>::iterator itlow,itup;

        mymap['a']=20;
        mymap['b']=40;
        mymap['c']=60;
        mymap['d']=80;
        mymap['e']=100;


        itlow=mymap.lower_bound ('b');  // itlow points to b
        itup=mymap.upper_bound ('d');   // itup points to e (not d!)
        mymap.erase(itlow,itup);        // erases [itlow,itup)

        // print content:
        for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';

    }

    std::cout << "----------EQUAL__RANGE-----------" << std::endl;
    {
    	ft::map<char,int> mymap;

        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;

        ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
        ret = mymap.equal_range('b');

        std::cout << "lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n';

        std::cout << "upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';

    }
}

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
#define COUNT (MAX_RAM / (int)sizeof(Buffer))

struct Buffer
{
    int idx;
    char buff[BUFFER_SIZE];
};

template <class key, class mapped>
void    display_map(ft::map<key, mapped> & m)
{
    if (m.empty()) {
        std::cout << "Empty map" << std::endl;
        return ;
    }
    typename ft::map<key,mapped>::iterator   it = m.begin();
    typename ft::map<key,mapped>::iterator   ite = m.end();
    while (it != ite)
    {
        std::cout << "[" << it->first << ":" << it->second << "]" << " " << std::endl;
        ++it;
    }
    std::cout << std::endl;
}

void  test_map_42()
{
    srand(4563215);
    ft::map<int, int> map_int;
    for (int i = 0; i < COUNT; ++i)
    {
        map_int.insert(ft::make_pair(rand(), rand()));
    }
    int sum = 0;
    for (int i = 0; i < COUNT; i++)
    {
        sum += map_int[i];
    }
    std::cout << sum << std::endl;
}

template <class key_type, class mapped_type>
ft::map<key_type, mapped_type>  generate_random_map(int n, int range)
{
    ft::map<key_type, mapped_type>  m;

    for (int i = 0; i < n; i++)
        m.insert(ft::make_pair(rand() % range, rand() % range));
    return (m);
}

void test_me(void)
{
    srand(time(NULL));
    std::cout << "============" << std::endl;
    std::cout << "CONSTRUCTORS" << std::endl;
    std::cout << "============" << std::endl << std::endl;

    std::cout << "----- 1. Default constructor -----" << std::endl;
    ft::map<int, int>  m;
    display_map(m);

    for (int i = 0; i < 10 ; i++)
        m.insert(ft::make_pair(rand() % 20, rand() % 20));
    display_map(m);
    
    std::cout << std::endl;
    std::cout << "----- 2. Range constructor -----" << std::endl;

    ft::map<int, int>    range_constructor_map(m.begin(), m.end());
    display_map(range_constructor_map);

    std::cout << std::endl;
    std::cout << "----- 3. Copy constructor -----" << std::endl;

    ft::map<int, int>   copy_constructor_map(range_constructor_map);
    display_map(copy_constructor_map);

    std::cout << std::endl;
    std::cout << "----- 4. Operator = -----" << std::endl;

    ft::map<int, int>   operator_equal_map;
    operator_equal_map = copy_constructor_map;
    display_map(operator_equal_map);

    std::cout << std::endl;
    std::cout << "========" << std::endl;
    std::cout << "CAPACITY" << std::endl;
    std::cout << "========" << std::endl << std::endl;
    
    std::cout << "----- 1. Empty -----" << std::endl;
    ft::map<int, int>   empty_map;
    if (empty_map.empty())
        std::cout << "Empty_map is empty" << std::endl;
    empty_map.insert(ft::make_pair(5,5));
    if (!empty_map.empty())
        std::cout << "Element inserted, map isn't empty" << std::endl;

    std::cout << std::endl;
    std::cout << "----- 2. Size -----" << std::endl;
    std::cout << "empty_map's size: " << empty_map.size() << std::endl;
    std::cout << "constructor's map size: " << m.size() << std::endl;

    std::cout << std::endl;
    std::cout << "----- 3. Max Size -----" << std::endl;
    std::cout << m.max_size() << std::endl;
    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "ELEMENT ACCESS" << std::endl;
    std::cout << "==============" << std::endl << std::endl;

    ft::map<char, std::string>  mymap;

    mymap['a'] = "an element";
    mymap['b'] = "another element";
    mymap['c'] = mymap['b'];

    std::cout << "mymap['a'] is " << mymap['a'] << std::endl;
    std::cout << "mymap['b'] is " << mymap['b'] << std::endl;
    std::cout << "mymap['c'] is " << mymap['c'] << std::endl;
    std::cout << "mymap['d'] is " << mymap['d'] << std::endl;

    std::cout << "mymap now contains " << mymap.size() << " elements." << std::endl;

    std::cout << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "MODIFIERS" << std::endl;
    std::cout << "=========" << std::endl << std::endl;

    std::cout << "----- 1.1 Insert: single element" << std::endl;
    ft::map<char, int>  insert_map;
    display_map(insert_map);
    insert_map.insert(ft::make_pair('a', 15));
    display_map(insert_map);
    insert_map.insert(ft::make_pair('z', 42));
    display_map(insert_map);
    insert_map.insert(ft::make_pair('d', 19));
    insert_map.insert(ft::make_pair('x', 19));
    insert_map.insert(ft::make_pair('b', 19));
    display_map(insert_map);

    std::cout << std::endl;
    std::cout << "----- 1.2 Insert: hint" << std::endl;
    ft::map<char, int>::iterator    insert_map_it = --(--insert_map.end());
    std::cout << "iterator is at: " << insert_map_it->first << std::endl;
    insert_map.insert(insert_map_it, ft::make_pair('y', 19));
    display_map(insert_map);

    std::cout << std::endl;
    std::cout << "----- 1.3 Insert: range" << std::endl;
    ft::map<char, int>  insert_map2;
    insert_map2.insert(insert_map.begin(), insert_map.end());
    display_map(insert_map2);

    std::cout << std::endl;
    std::cout << "----- 2.1 Erase: position -----" << std::endl;
    ft::map<char, int>  erase_map = insert_map;
    ft::map<char, int>::iterator    erase_it = erase_map.find('d');
    if (erase_it != erase_map.end())
        erase_map.erase(erase_it);
    std::cout << "erase d with iterator" << std::endl;
    display_map(erase_map);

    std::cout << std::endl;
    std::cout << "----- 2.2 Erase: key -----" << std::endl;
    erase_map.erase('z');
    std::cout << "erase z with key" << std::endl;
    display_map(erase_map);

    std::cout << std::endl;
    std::cout << "----- 2.3 Erase: range -----" << std::endl;
    erase_map.erase(erase_map.begin(), ++(++erase_map.begin()));
    std::cout << "erase map.begin() and map.begin() + 1" << std::endl;
    display_map(erase_map);

    std::cout << std::endl;
    std::cout << "----- 3. Swap -----" << std::endl;
    ft::map<char,int> foo,bar;

    foo['x']=100;
    foo['y']=200;
    std::cout << "foo: ";
    display_map(foo);

    bar['a']=11;
    bar['b']=22;
    bar['c']=33;
    std::cout << "bar: ";
    display_map(bar);

    foo.swap(bar);

    std::cout << "foo contains:" << std::endl;
    display_map(foo);
    std::cout << "foo size: " << foo.size() << std::endl;

    std::cout << "bar contains:" << std::endl;
    display_map(bar);
    std::cout << "bar size: " << bar.size() << std::endl;

    std::cout << std::endl;
    std::cout << "----- 4. Clear -----" << std::endl;
    ft::map<char, int>  clear_map = erase_map;
    display_map(clear_map);
    clear_map.clear();
    display_map(clear_map);
    std::cout << "clear_map's size is " << clear_map.size() << std::endl;
    clear_map.insert(ft::make_pair('c', 19));
    display_map(clear_map);

    std::cout << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "OBSERVERS" << std::endl;
    std::cout << "=========" << std::endl << std::endl;
    std::cout << "----- 1. Key_comp -----" << std::endl;
    ft::map<char,int> mymap_comp;

    ft::map<char,int>::key_compare mycomp = mymap_comp.key_comp();

    mymap_comp['a']=100;
    mymap_comp['b']=200;
    mymap_comp['c']=300;

    std::cout << "mymap_comp contains:" << std::endl;

    char highest_key = mymap_comp.rbegin()->first;     // key value of last element

    ft::map<char,int>::iterator it_comp = mymap_comp.begin();
    do {
      std::cout << it_comp->first << " => " << it_comp->second << std::endl;
    } while ( mycomp((*it_comp++).first, highest_key) );

    std::cout << std::endl;
    std::cout << "----- 2. Value_comp -----" << std::endl;
    ft::map<char,int> mymap_value;

    mymap_value['x']=1001;
    mymap_value['y']=2002;
    mymap_value['z']=3003;

    std::cout << "mymap_value contains:" << std::endl;

    ft::pair<char,int> highest = *mymap_value.rbegin();          // last element

    ft::map<char,int>::iterator it_value = mymap_value.begin();
    do {
      std::cout << it_value->first << " => " << it_value->second << std::endl;
    } while ( mymap_value.value_comp()(*it_value++, highest) );

    std::cout << std::endl;
    std::cout << "==========" << std::endl;
    std::cout << "OPERATIONS" << std::endl;
    std::cout << "==========" << std::endl << std::endl;

    std::cout << "----- 1. Find -----" << std::endl;
    display_map(insert_map);
    ft::map<char, int>::iterator find_it = insert_map.find('b');
    std::cout << "[" << find_it->first << ":" << find_it->second << "]" << std::endl;
    ft::map<char, int>::const_iterator const_find_it = insert_map.find('z');
    std::cout << "[" << const_find_it->first << ":" << const_find_it->second << "]" << std::endl;

    char search = 'p';
    ft::map<char, int>::iterator find_it_notexist = insert_map.find(search);
    if (find_it_notexist == insert_map.end())
        std::cout << "Could not find key [" << search << "] in map" << std::endl;

    std::cout << std::endl;
    std::cout << "----- 2. Count -----" << std::endl;
    display_map(foo);
    std::cout << "count a: " << foo.count('a') << std::endl;
    std::cout << "count c: " << foo.count('c') << std::endl;
    std::cout << "count x: " << foo.count('x') << std::endl;

    std::cout << std::endl;
    std::cout << "----- 3. Lower_bound / Upper_bound -----" << std::endl;
    ft::map<char,int> lb_map;
    ft::map<char,int>::iterator itlow, itup;

    lb_map['a']=20;
    lb_map['c']=40;
    lb_map['d']=60;
    lb_map['e']=80;
    lb_map['f']=100;

    itlow = lb_map.lower_bound('b');  // itlow points to c
    itup = lb_map.upper_bound('d');   // itup points to e (not d!)

    display_map(lb_map);
    lb_map.erase(itlow, itup);
    display_map(lb_map);

    std::cout << std::endl;
    std::cout << "----- 4. Equal_range -----" << std::endl;
    ft::map<char,int> equal_range_map;

    equal_range_map['a']=10;
    equal_range_map['b']=20;
    equal_range_map['c']=30;

    ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
    ret = equal_range_map.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << std::endl;

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << std::endl;

    std::cout << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "ITERATORS" << std::endl;
    std::cout << "=========" << std::endl << std::endl;

    ft::map<int, int>   iterators_map = generate_random_map<int, int>(10, 100);
    ft::map<int, int>::iterator it_map_it = iterators_map.begin();
    ft::map<int, int>::iterator it_map_ite = iterators_map.end();
    std::cout << "display map with red black tree function: " << std::endl;
    display_map(iterators_map);
    std::cout << "display map with iterators" << std::endl;
    while (it_map_it != it_map_ite)
    {
        std::cout << "[" << it_map_it->first << ":" << it_map_it->second << "]" << " ";
        ++it_map_it;
    }
    std::cout << std::endl;

    std::cout << "----- Default constructor -----" << std::endl;
    ft::map<int, int>::iterator original_it;
    std::cout << "----- Assignation -----" << std::endl;
    original_it = m.begin();
    std::cout << "----- Copy constructor -----" << std::endl;
    ft::map<int, int>::iterator it(original_it);
    std::cout << "----- Equal comparison -----" << std::endl;
    if (original_it == m.begin() && it == m.begin())
        std::cout << "Default constructor, assignation and copy constructor worked" << std::endl;
    std::cout << "----- Unequal comparison -----" << std::endl;
    ++original_it;
    if (original_it != it)
        std::cout << "Iterators are not equal after incrementation" << std::endl;
    std::cout << "----- * dereferencement -----" << std::endl;
    std::cout << "map used is" << std::endl;
    display_map(m);
    std::cout << "first value: [" << (*it).first << ":" << (*it).second << "]" << std::endl;
    std::cout << "----- -> dereferencement -----" << std::endl;
    std::cout << "first value: [" << it->first << ":" << it->second << "]" << std::endl;
    std::cout << "----- Pre increment -----" << std::endl;
    ++it;
    std::cout << "second value: [" << it->first << ":" << it->second << "]" << std::endl;
    std::cout << "----- Post increment -----" << std::endl;
    std::cout << "second value(post incr): [" << it->first << ":" << (it++)->second << "]" << std::endl;
    std::cout << "third value: [" << it->first << ":" << it->second << "]" << std::endl;
    std::cout << "----- Pre decrement -----" << std::endl;
    --it;
    std::cout << "second value: [" << it->first << ":" << it->second << "]" << std::endl;
    std::cout << "----- Post decrement -----" << std::endl;
    std::cout << "second value: [" << it->first << ":" << (it--)->second << "]" << std::endl;
    std::cout << "first value: [" << it->first << ":" << it->second << "]" << std::endl;
    
    std::cout << std::endl;
    std::cout << "=================" << std::endl;
    std::cout << "REVERSE_ITERATORS" << std::endl;
    std::cout << "=================" << std::endl << std::endl;

    std::cout << "display with red-black tree function" << std::endl;
    display_map(m);
    ft::map<int, int>::reverse_iterator rev_it = m.rbegin();
    ft::map<int, int>::reverse_iterator rev_ite = m.rend();
    std::cout << "display with reverse iterators" << std::endl;
    while (rev_it != rev_ite)
    {
        std::cout << "[" << (*rev_it).first << ":" << (*rev_it).second << "]" << " ";
        ++rev_it;
    }
    std::cout << std::endl;
}

int main()
{
    struct timeval  time;
    gettimeofday(&time, NULL);
    long totalTime = (time.tv_sec * 1000000) + (time.tv_usec);

    test_map_cppcom();
    test_map_42();
    test_me();

    gettimeofday(&time, NULL);
    totalTime = ((time.tv_sec * 1000000) + (time.tv_usec) - totalTime);
    std::cout << totalTime << std::endl;
    return (0);
}