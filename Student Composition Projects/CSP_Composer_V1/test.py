#!/usr/bin/env python
# Tests the relevant functions

from World import World

# Create World
w = World(90)

# Add Some Variables and Values
w.addVar('A', 30)
w.addVar('B', 35)
w.addVar('C', 30)
w.addVar('D', 70)
w.addVar('E', 40)

w.addValue('q', 95)
w.addValue('r', 70)
w.addValue('s', 40)

# Add Constraints
w.addBinE('A', 'B')
w.addBinNE('C', 'D')
w.addBinS('A','E','r','s')

# Set Limits
w.limits = [1,3]

# Add Assignments and Test as we go
# When Empty
assert w.checkUnaryI(), 'UnaryI Fail when empty'
assert w.checkUnaryE(), 'UnaryE Fail when empty'
assert w.checkBinE(), 'BinE Fail when empty'
assert w.checkBinNE(), 'BinNE Fail when empty'
assert w.checkBinS(), 'BinS Fail when empty'
# No Conflicts
w.addAssignment('A', 'q')
w.addAssignment('B', 'q')
w.addAssignment('C', 'q')
w.addAssignment('D', 'r')
w.addAssignment('E', 's')
assert w.checkMinCapacity(), 'MinCapacity Should have passed'
assert w.checkMaxCapacity(), 'MaxCapacity Should have passed'
assert w.checkUnaryI(), 'UnaryI Fail at First Round of Assignment'
assert w.checkUnaryE(), 'UnaryE Fail at First Round of Assignment'
assert w.checkBinE(), 'BinE Fail at First Round of Assignment'
assert w.checkBinNE(), 'BinNE Fail at First Round of Assignment'
assert w.checkBinS(), 'BinS Fail at First Round of Assignment'
assert w.isValid(), 'Output is Valid!'
assert w.isComplete(), 'Output is Complete'
# Remove Assignment and add Conlicting Ones
# Remove
w.removeAssignment('A')
w.removeAssignment('B')
w.removeAssignment('C')
w.removeAssignment('D')
w.removeAssignment('E')
# Add and Test
w.addAssignment('A', 'r')
w.addAssignment('B', 'q')
w.addAssignment('C', 'r')
w.addAssignment('D', 'r')
w.addAssignment('E', 's')
assert not w.checkBinE(), 'BinE Did not Fail at Conflicting Round'
assert not w.checkBinNE(), 'BinNE Did not Fail at Conflicting Round'
assert not w.checkBinS(), 'BinS Did not Fail at Conflicting Round'
assert w.checkBottomLimit(), 'Bottom Limit not Fulffiled'
assert w.checkTopLimit(), 'Top Limit Exceeded'




