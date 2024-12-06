    
#STACK BUILDER
    int	*convert_argv(int argc, char **argv)
    {
        #receive inputs on main;
	    #validate if the inputs are numbers;
	    #convert each int using atoi;
	    #save it in an int array;
    }
    

    t_list	*stack_builder(int argc, char **argv)
    {
        #create the linked list 'a';
            #it must have to be in the right order;
        #freed allocated memory for array of ints received from convert_arg;
    }



    #MOVEMENTS
    #movements must have to deal with the stack 'a' created in stack_builder;
        #4 basic movements, varying which stack we call ('a' or 'b');
        #3 aggregate movements, that work in both stacks;
    #movements can create a new stack, called 'b', if necessary; 
        #we are going to call stack_builder from movements.c;