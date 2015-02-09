__author__ = 'nathan'


class CollisionChecker:
    """
    This class defines the configuration space of the composition by creating a probabilistic model for whether a
    configuration should be included or excluded from the sampled representation of the space. This probabilistic model
    depends on the following different parameters: the pitch difference between voices, the difference in duration
    between voices, whether a pitch fits within the key of the voice, and whether the duration fits within the assumed
    duration of the given voice.
    """
    def __init__(self):
        pass

    def is_valid(self, q):
        return False