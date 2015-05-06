# Creates the log file for the CSP composer V2

class Logger:
	# Constructor
	def __init__(self, fileName, reporting = False):
		self.f = open(fileName, 'w')
		self.reporting = reporting

		if self.reporting:
			print "Verbose mode selected..."

	# Logs the statistics after one iteration of the composer
	def logIteration(self, c, ite):
		self.f.write('******************************************\n')
		self.f.write('************** ITERATION: ' + str(ite) + ' **************\n')
		self.f.write('******************************************\n')

		# Total Notes Assigned
		self.f.write('Notes assigned: ' + str(c.composition.countNotes()) + '\n')
		self.f.write('Silences: ' + str(c.composition.countSilence()) + '\n')
		self.f.write('Register Occurence: ' + str(c.composition.countRegisters()) + '\n')

		if self.reporting:
			print "Completed iteration: " + str(ite) + " Total notes assigned: " + str(c.composition.countNotes()) + " ..."

	# Make final log
	def logCompletion(self, c, ite):
		self.f.write('******************************************\n')
		self.f.write('************* FINAL ITERATION ************\n')
		self.f.write('******************************************\n')

		# Total Notes Assigned
		self.f.write('Notes assigned: ' + str(c.composition.countNotes()) + '\n')
		self.f.write('Silences: ' + str(c.composition.countSilence()) + '\n')
		self.f.write('Duration (s): ' + str(c.timeParameters.get()[0]) + '\n')
		self.f.write('Registers Used: ' + str(c.composition.enumerateRegisters()) + '\n')
		self.f.write('Register Occurence: ' + str(c.composition.countRegisters()) + '\n')
