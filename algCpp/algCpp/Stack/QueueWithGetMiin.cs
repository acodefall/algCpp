using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TreeAlg
{

    /* Based on StackWithGetMinimumX 
     * //@SH09 Stack_024_Stack with GetMin functionality_SH09
       //@SH09 Stack_025_Steps for Construct Stack with GetMin functionality_SH09
    */
    public class QueueWithGetMiin
    {
        public void callQueueWithGetMiin()
        {
            QueaueWithGetMin objQueueWithGetMiin = new QueaueWithGetMin();

            objQueueWithGetMiin.EnQ(23);
            objQueueWithGetMiin.EnQ(2);
            objQueueWithGetMiin.EnQ(21);
            objQueueWithGetMiin.EnQ(13);
            objQueueWithGetMiin.EnQ(1);

            
            for(int i = 0; i < objQueueWithGetMiin.Count(); i++)
            {
                int f = objQueueWithGetMiin.DeeQ();
                Console.WriteLine(f);
                Console.WriteLine(objQueueWithGetMiin.GetMin());
            }
        }
    }

    public class QueaueWithGetMin
    {
        private StackWithGetMinimum stPushOnly = new StackWithGetMinimum();
        private StackWithGetMinimum stPopOnly  = new StackWithGetMinimum();
        public void EnQ(int item)
        {
            stPushOnly.Push(item);
        }

        public int DeeQ()
        {
            if(stPopOnly.Count() == 0)
            {
                
                while (stPushOnly.Count() > 0)
                {
                    int f = stPushOnly.Count();
                    stPopOnly.Push(stPushOnly.Pop());
                }
            }
            return stPopOnly.Pop();
        }

        public int Count()
        {
            return Math.Max(stPushOnly.Count(), stPopOnly.Count());
        }

      

        public int GetMin()
        {
            int i1 = -1;
            int i2 = -1;
            if (stPushOnly.Count() != 0)
                i1 = stPushOnly.getMin();

            if(stPopOnly.Count() != 0)
            {
                i2 = stPopOnly.getMin();
            }

            return Math.Min(i1, i2);

            //return Math.min((stPushOnly.size() == 0) ? Integer.MAX_VALUE : stackMinimum1.getMinimum(), stackMinimum2.size() == 0 ? Integer.MAX_VALUE : stackMinimum2.getMinimum());
        }
    }

}
