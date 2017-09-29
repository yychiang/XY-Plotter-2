
comPort='com4'
flag=1;
%geoList={['Lx1600y1600a'];['Da'];['Lx10y10a'];['Ua'];['Lx1600y1600a'];['Da'];['Lx0y100a'];['Ua'];['Lx1600y1600a'];['Da'];['Lx600y1400a'];['Ua'];};%
%geoList={['Cx800y800r200a'];['Cx800y800r240a'];['Cx800y800r260a'];['Cx800y800r280a'];['Cx800y800r100a'];['Cx800y800r120a'];['Cx800y800r140a'];['Cx800y800r160a'];['Cx800y800r180a']};
%geoList={['Da'];['Ua'];['Da'];['Ua'];['Da'];['Ua'];['Da'];['Ua']};
s=serial(comPort);
set(s,'DataBits',8);
set(s,'StopBits',1);
set(s,'BaudRate',9600);
set(s,'Parity','none');
fopen(s);
a='b';
while (a~='a')
    a=fread(s,1,'uchar')
end
if(a=='a')
    disp('serial read');
end

 for i=1:length(geoList)
  fprintf(s,'%c',geoList{i});
  while (a~='x')
    a=fread(s,1,'uchar');
  end
  if(a=='x')
    disp('x read');
  end
  a='a';
end
% mbox=msgbox('Serial Communictions setup'); uiwait(mbox);
% %A=fscanf(s,'%u')


fclose(s)

