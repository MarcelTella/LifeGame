%
%Example usage
% videoscript('a.txt',2,30);
function videoscript (filename, cellSize, framerate)

fid = fopen(filename);

%Load Boards
boards = {};


%Initialising
matrixes = {};
matrix = 0;
first = true;
%Getting first line
tline = fgets(fid);
while ischar(tline)
    
    %Getting line and parsing string
    tline = strtrim(tline);
    row = strsplit(tline);
    row = strncmp('1', row, 1);
    if (first == true)
        matrix = row;
    end
    %C{end+1} = row;
    
    %Creating matrix and accumulating them in matrixes once they are
    %completed (they are created row by row)
    if (length(row) == 1)
        %Matrix full
        matrixes{end+1} = createBoard(matrix,cellSize);
        first = true;
        matrix = 0;
        tline = fgets(fid);
        continue;
    elseif (first ~= true)
        matrix = [matrix; row];
    end
    
    if first == true
        first = false;
    end
    
    tline = fgets(fid);
end

fclose(fid);

%Print Boards
video('GameOfLife.avi',matrixes)


%
%   Utilities
%
function newM = createBoard(M,cellSize)
    newM = zeros(size(M)*cellSize);
    for i=1:size(M,1)
        for j=1:size(M,2)
            newM(i*cellSize-cellSize+1:i*cellSize, j*cellSize-cellSize+1:j*cellSize) = M(i,j);
        end
    end
end

function video(name, images)   
        %Open video object
        writerObj = VideoWriter(name);
        open(writerObj);

        for i=1:length(images)   
            for j=1:framerate
                writeVideo(writerObj,images{i});
            end
        end
        close(writerObj);
end

end