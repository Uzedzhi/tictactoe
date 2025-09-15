A SUPER tictactoe game in windows terminal on plain C. 
Rules:
1. First person places a symbol
2. next one places it in a big 3x3 grid, which first person placed on.
   For example:
1st person:
```
                         II               II                  
               |   |     II     |   |     II     |   |        
            ___|___|___  II  ___|___|___  II  ___|___|___     
               |   |     II     |   |     II     |   |        
            ___|___|___  II  ___|___|___  II  ___|___|___     
               |   |     II     |   |     II     |   |        
               |   |     II     |   |     II     |   |        
                         II               II                  
          IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII   
                         II               II                  
               |   |     II     |   |     II     |   |        
            ___|___|___  II  ___|___|___  II  ___|___|___     
               |   |     II     |   | X   II     |   |        
            ___|___|___  II  ___|___|___  II  ___|___|___     
               |   |     II     |   |     II     |   |        
               |   |     II     |   |     II     |   |        
                         II               II                  
          IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII   
                         II               II                  
               |   |     II     |   |     II     |   |        
            ___|___|___  II  ___|___|___  II  ___|___|___     
               |   |     II     |   |     II     |   |        
            ___|___|___  II  ___|___|___  II  ___|___|___     
               |   |     II     |   |     II     |   |        
               |   |     II     |   |     II     |   |        
                         II               II
```
when the 2nd person MUST play in a center-right big grid<br>
2nd plays:
```
                         II               II                  
               |   |     II     |   |     II     |   |        
            ___|___|___  II  ___|___|___  II  ___|___|___     
               |   |     II     |   |     II     |   |        
            ___|___|___  II  ___|___|___  II  ___|___|___     
               |   |     II     |   |     II     |   |        
               |   |     II     |   |     II     |   |        
                         II               II                  
          IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII   
                         II               II                  
               |   |     II     |   |     II     |   |        
            ___|___|___  II  ___|___|___  II  ___|___|___     
               |   |     II     |   | X   II   O |   |        
            ___|___|___  II  ___|___|___  II  ___|___|___     
               |   |     II     |   |     II     |   |        
               |   |     II     |   |     II     |   |        
                         II               II                  
          IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII   
                         II               II                  
               |   |     II     |   |     II     |   |        
            ___|___|___  II  ___|___|___  II  ___|___|___     
               |   |     II     |   |     II     |   |        
            ___|___|___  II  ___|___|___  II  ___|___|___     
               |   |     II     |   |     II     |   |        
               |   |     II     |   |     II     |   |        
                         II               II
```
