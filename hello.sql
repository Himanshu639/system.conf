create database Library3;
use Library3;
create table borrower(rollin int primary key,name varchar(20),dateofissue date,nameofbook varchar(20),status varchar(20));
create table fine(rollno int,foreign key(rollno) references borrower(rollin),returndate date,amount int);
insert into borrower values(1,'abc','2023-08-25','SEPM','PEN');
insert into borrower values(2,'xyz','2023-09-01','AI','PEN');
insert into borrower values(3,'pqr','2023-08-15','DBMS','PEN');
delimiter $

create procedure calc_fine_lib6(in roll int)  
	begin 
	declare 
		fine1 int; 
	declare 
		noofdays int; 
	declare 
		issuedate date; 
	declare 
		exit handler for SQLEXCEPTION select'create table definition'; 
		select dateofissue into issuedate from borrower where rollin=roll; 
		select datediff(curdate(),issuedate) into noofdays; 
		
		if noofdays>15 and noofdays<=30 then set fine1=noofdays*5; 
			insert into fine values(roll,curdate(),fine1); 
		elseif noofdays>30 then set fine1=((noofdays-30)*50) + 15*5; 
			insert into fine values(roll,curdate(),fine1); 
		else 
			insert into fine values(roll,curdate(),0); 
		end if; 
		
		update borrower set status='return' where rollin=roll; 
end $

delimiter ;
call calc_fine_lib6(1);
call calc_fine_lib6(2);
call calc_fine_lib6(3);

select "⇓⇓⇓ Following is the borrower table ⇓⇓⇓" as "";
select * from borrower;
select "⇓⇓⇓ Following is the fine table ⇓⇓⇓" as "";
select * from fine;

drop database Library3;
