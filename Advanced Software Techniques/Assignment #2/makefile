#Linux
#OBJEXT = .o
#OBJFILE = obj/
#SRCFILE = src/
#CFLAG = -c -o
#LDFLAGS = -o
#RM = rm
#CLCMD = $(CC) -o $(EXE) $(OBJ)
#End Linux

#Windows
OBJEXT = .obj
OBJFILE = obj\\
SRCFILE = src\\
CFLAG = /c /Fo
LDFLAGS = /Fe
RM = del
CLCMD = $(CC) $(OBJ) $(LDFLAGS)$(EXE)
#End Windows

#General
MAIN = main
CREATERANNUM = createRanNum
DETERMINEGUESSRESULT = determineGuessResult
GETANDVALIDATEUSERGUESS = getAndValidateUserGuess
SHOWUSERGUESSRESULT = showUserGuessResult
HEADERS = $(SRCFILE)proto.h
OBJ = $(OBJFILE)$(MAIN)$(OBJEXT) $(OBJFILE)$(CREATERANNUM)$(OBJEXT) $(OBJFILE)$(DETERMINEGUESSRESULT)$(OBJEXT) $(OBJFILE)$(GETANDVALIDATEUSERGUESS)$(OBJEXT) $(OBJFILE)$(SHOWUSERGUESSRESULT)$(OBJEXT)
EXE = GuessGame.exe

$(EXE): $(OBJ) 
	$(CLCMD)

$(OBJFILE)$(MAIN)$(OBJEXT): $(SRCFILE)main.c $(HEADERS)
	$(CC) $(SRCFILE)main.c $(CFLAG)$@

$(OBJFILE)$(CREATERANNUM)$(OBJEXT): $(SRCFILE)createRanNum.c $(HEADERS)
	$(CC) $(SRCFILE)createRanNum.c $(CFLAG)$@
	
$(OBJFILE)$(DETERMINEGUESSRESULT)$(OBJEXT): $(SRCFILE)determineGuessResult.c $(HEADERS)
	$(CC) $(SRCFILE)determineGuessResult.c $(CFLAG)$@

$(OBJFILE)$(GETANDVALIDATEUSERGUESS)$(OBJEXT): $(SRCFILE)getAndValidateUserGuess.c $(HEADERS)
	$(CC) $(SRCFILE)getAndValidateUserGuess.c $(CFLAG)$@

$(OBJFILE)$(SHOWUSERGUESSRESULT)$(OBJEXT): $(SRCFILE)showUserGuessResult.c $(HEADERS)
	$(CC) $(SRCFILE)showUserGuessResult.c $(CFLAG)$@

clean:
	$(RM) $(OBJ)
	$(RM) $(EXE)
