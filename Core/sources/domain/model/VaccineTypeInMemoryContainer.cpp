#include "../../../headers/domain/container/VaccineTypeInMemoryContainer.h"
#include <algorithm>

namespace domain::container {

    bool VaccineTypeInMemoryContainer::existsByCode(const std::string& code) const {
        return std::any_of(vaccineTypes_.begin(), vaccineTypes_.end(),
            [&code](const std::unique_ptr<model::VaccineType>& vt) {
                return vt->getCode() == code;
            });
    }

    void VaccineTypeInMemoryContainer::save(std::unique_ptr<model::VaccineType> vaccineType) {
        if (vaccineType) {
            vaccineTypes_.push_back(std::move(vaccineType));
        }
    }

    const std::vector<std::unique_ptr<model::VaccineType>>&
    VaccineTypeInMemoryContainer::getAll() const {
        return vaccineTypes_;
    }

} // namespace domain::container