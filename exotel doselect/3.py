class Question:
   gQid = 0
   qid = 0
   qname = ""
   options = []
   avg_marks = 0.0

   def init (qname, options):
    #   //init is the standerd init(self,variables) function in python
      self.qid= gQid
      gQid = gQid+1
      self.qname= qname
      self.options= options
      self.avg_marks= sum(options)/(len(options)*1.0)
      self.avg_marks = float("{0:.2f}".format(self.avg_marks))
    #   sum of marks in options divided by length of options
    #   (rounded to two decimal palces)
   def getQid():
      return self.qid
   def getAvgMarks():
      return self.avg_marks

class Paper:
   questions = []
   avg_marks_of_paper = 0.0

   def init ():
      self.questions= []
      self.avg_marks_of_paper= 0.0
   def addQuestion (question):
    #   //question is an object of class Question
      if question.getAvgMarks() <= 1.0 and question.getAvgMarks() >= -1.0 :
         self.questions.append(question.getQid())
         self.avg_marks_of_paper = self.avg_marks_of_paper + question.getAvgMarks()
   def getAvgMarksOfPaper():
      return self.avg_marks_of_paper
   def getQuestionPaper():
      return self.questions
