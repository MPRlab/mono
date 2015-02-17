"""
    Copyright Nathan Hughes 2015

    This file is part of code developed for the Music Perception and Robotics
    Laboratory at Worcester Polytechnic Institute.

    This file is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This file is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    somewhere in this repository.  If not, see <http://www.gnu.org/licenses/>.
"""


__author__ = 'nathan'


from abc import ABCMeta, abstractmethod


class VoiceGenerator:
    """
    This class is an abstract base class (abc) for the different possible voice generators (i.e. sampling methods of the
    configuration space)
    """
    __meta_class__ = ABCMeta

    def __init__(self):
        pass

    @abstractmethod
    def get_new_pitch(self):
        pass

    @abstractmethod
    def get_new_duration(self):
        pass

    @abstractmethod
    def get_duration_score(self, duration):
        pass

    @abstractmethod
    def get_pitch_score(self, pitch):
        pass
