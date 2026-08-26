# Write your MySQL query statement below
select 
    case 
        when id = (select max(id) from Seat) and mod(id,2)=1 #last id n its odd place
            then id # keep as it is
        when mod(id,2) = 1 #odd place --> increment the id
            then id+1
        else
            id-1 # even place --> decrement the id
    end as id, student
from Seat
order by id;