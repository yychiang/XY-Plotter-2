function cout = erode(u,b,n)
%ERODE	Erode a binary image. chiang
%	BWOUT = ERODE(BW,'method') erodes the binary image BW
%	using 'method'. Possible methods are 'erode','skeleton',
%	'shrink', or 'thin'.  The method 'erode' removes all 
%	8-connected pixels on the boundary of objects.  'skeleton' 
%	is the same as 'erode' except that pixels that are part of
%	each object skeleton are maintained.  'shrink' removes
%	pixels from objects until they become points. 'thin' is 
%	the same as 'shrink' except that objects are thinned 
%	to lines instead of points.  The default method is 'thin'.
%	All the methods except 'erode' preserve the Euler number.
%	BW must be a binary image (it can only contain the 
%	values 0 and 1).
%
%	BWOUT = ERODE(BW, SE) performs a generalized erosion of 
%	the binary image BW with the structuring element SE.  The
%	image will be eroded wherever BW contains a set of pixels
%	that don't match the non-zero pixels in the structuring
%	element SE. SE must contain only 1's or 0's.
%
%	ERODE(BW,'method',N), ERODE(BW,SE,N) or ERODE(BW,N) performs
%	ERODE N times.
%
%	See also DILATE, BWMORPH, BWEULER.

%	Clay M. Thompson 8-9-93
%	Copyright (c) 1993 by The MathWorks, Inc.
%	$Revision: 1.11 $  $Date: 1993/10/21 12:59:32 $

error(nargchk(1,3,nargin));

if nargin==1, b = 'thin'; n = 1; end
if nargin==2,
  if ~isstr(b) & max(size(b))==1,
    n = b; b = 'thin';
  else
    n = 1;
  end
end

if isstr(b), % method string
  method = [lower(b)]; % Protect against short method string.
  if method(1)=='e' | all(method(1:2)=='sh') |  ...
     all(method(1:2)=='sk') | method(1)=='t',
    c = bwmorph(u,method,n);
  else
    error([deblank(method),' is an ambiguous or unknown method.']);
  end

else
  if prod(size(u))<prod(size(b)), % Switch arguments for faster computation.
    tmp = u; u = b; b = tmp;
    switched = 1;
  else
    switched = 0;
  end

  [mu,nu] = size(u);
  sten = rot90(b,2);
  [ms,ns] = size(sten);

  % Determine indexes into central part that is the same size as the original U.
  if switched,
    rows = floor((mu-1)/2) + (1:ms);
    cols = floor((nu-1)/2) + (1:ns);
  else
    rows = floor((ms-1)/2) + (1:mu);
    cols = floor((ns-1)/2) + (1:nu);
  end

  c = ones(ms+mu-1,ns+nu-1);
  for i=1:ms
  	for j=1:ns
  		w = sten(ms-i+1,ns-j+1);
  		if w~=0,
  			c(i:i+mu-1,j:j+nu-1) = c(i:i+mu-1,j:j+nu-1) & u;
  		end
  	end
  end
  
  for i=2:n,
    a = c(rows,cols);
    c = ones(ms+mu-1,ns+nu-1);
    for i=1:ms
  	  for j=1:ns
        w = sten(ms-i+1,ns-j+1);
  		if w~=0,
  		  c(i:i+mu-1,j:j+nu-1) = c(i:i+mu-1,j:j+nu-1) & u;
  		end
      end
    end
  end

  % Return the central part that is the same size as the original U.
  c = c(rows,cols);

end

if nargout==0, imshow(c,2), return, end
cout = c;