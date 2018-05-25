main()
{ int k, n, m;

      k = 0;
      if ($0 != 0) { 
        n = $1;
        while (n != 0)  
        {
            m = n;
            while (m != 0) 
            {
              m = m-1;
              k = k+1;
            }
            n = n-1;
        }
      } 
      return k;
}
