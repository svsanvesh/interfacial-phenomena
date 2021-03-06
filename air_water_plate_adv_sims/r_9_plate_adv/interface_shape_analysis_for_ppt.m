clear all
clc


Domain = 0.015;
theta0 = 30*pi/180;
ms=10;
lw=1


x = linspace(-Domain/2,Domain/2,100);
yinit = -0.0013 + 0.0027./(tan(theta0).*exp((x+ 0.0075)/0.0027));



figure


ms=8;
lw=1.5;
plot(x +Domain/2,yinit,'k*','LineWidth',lw, 'MarkerSize',ms )
ylabel('Downward moving plate','FontWeight','Bold','FontSize',20);
xlabel('Particle diameter (\mum)','FontWeight','Bold','FontSize',20);
set(gca,'Fontsize',12,'Fontname','Times New Roman')
set(gca,'XMinorTick','on','YMinorTick','on','TickDir','in')
                


setWH(gcf,9,6)
hold on
A=load('interface_profile_t4.600000.dat');
ms=8;
lw=0.4;



plot(A(:,1) +Domain/2,A(:,2) ,'gx', 'MarkerSize',ms )
ylabel('Downward moving plate','FontWeight','Bold','FontSize',20);
xlabel('Particle diameter (\mum)','FontWeight','Bold','FontSize',20);
set(gca,'Fontsize',12,'Fontname','Times New Roman')
set(gca,'XMinorTick','on','YMinorTick','on','TickDir','in')

setWH(gcf,9,6)
hold on


B=load('interface_profile_t4.700000.dat');


ms=8;
lw=1;



% plot(A(:,1),,'r.');
plot(B(:,1) +Domain/2,B(:,2) ,'cs', 'MarkerSize',ms )
ylabel('Downward moving plate','FontWeight','Bold','FontSize',20);
xlabel('Particle diameter (\mum)','FontWeight','Bold','FontSize',20);
set(gca,'Fontsize',12,'Fontname','Times New Roman')
set(gca,'XMinorTick','on','YMinorTick','on','TickDir','in')

setWH(gcf,9,6)

hold on
C=load('interface_profile_t4.800000.dat');
%A=sort(A,1);
ms=8;
lw=1;



% plot(A(:,1),,'r.');
plot(C(:,1) +Domain/2,C(:,2) ,'bd', 'MarkerSize',ms )
ylabel('Downward moving plate','FontWeight','Bold','FontSize',20);
xlabel('Particle diameter (\mum)','FontWeight','Bold','FontSize',20);
set(gca,'Fontsize',12,'Fontname','Times New Roman')
set(gca,'XMinorTick','on','YMinorTick','on','TickDir','in')

setWH(gcf,9,6)

hold on

D=load('interface_profile_t4.900000.dat');

ms=8;
lw=1;



% plot(A(:,1),,'r.');
plot(D(:,1) +Domain/2,D(:,2) ,'kv', 'MarkerSize',ms )
ylabel('Downward moving plate','FontWeight','Bold','FontSize',20);
xlabel('Particle diameter (\mum)','FontWeight','Bold','FontSize',20);
set(gca,'Fontsize',12,'Fontname','Times New Roman')
set(gca,'XMinorTick','on','YMinorTick','on','TickDir','in')

setWH(gcf,9,6)

hold on







E=load('interface_profile_t5.000000.dat');

ms=8;
lw=1;



% plot(A(:,1),,'r.');
plot(E(:,1) +Domain/2,E(:,2) ,'r+', 'MarkerSize',ms )
ylabel('Downward moving plate','FontWeight','Bold','FontSize',20);
xlabel('Particle diameter (\mum)','FontWeight','Bold','FontSize',20);
set(gca,'Fontsize',12,'Fontname','Times New Roman')
set(gca,'XMinorTick','on','YMinorTick','on','TickDir','in')

setWH(gcf,9,6)

hold on

legend ('Static meniscus ' , 't = 4.6', 't = 4.7', 't = 4.8', 't = 4.9', 't = 5.0')






