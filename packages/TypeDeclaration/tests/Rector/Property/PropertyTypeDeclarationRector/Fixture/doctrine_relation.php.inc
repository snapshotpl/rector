<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\PropertyTypeDeclarationRector\Fixture;

use Doctrine\ORM\Mapping as ORM;

class DoctrineRelation
{
    /**
     * @ORM\OneToMany(targetEntity="App\Product")
     */
    private $products;

    /**
     * @ORM\ManyToMany(targetEntity="App\Car")
     */
    private $cars;

    /**
     * @ORM\ManyToOne(targetEntity="App\Company\Entity\Company", inversedBy="userBuildings")
     * @ORM\JoinColumn(name="company_id", referencedColumnName="id", nullable=true)
     */
    private $company;

    /**
     * @ORM\OneToOne(targetEntity="App\Company\Entity\Company")
     */
    private $company2;
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\PropertyTypeDeclarationRector\Fixture;

use Doctrine\ORM\Mapping as ORM;

class DoctrineRelation
{
    /**
     * @ORM\OneToMany(targetEntity="App\Product")
     * @var \App\Product[]|\Doctrine\Common\Collections\Collection
     */
    private $products;

    /**
     * @ORM\ManyToMany(targetEntity="App\Car")
     * @var \App\Car[]|\Doctrine\Common\Collections\Collection
     */
    private $cars;

    /**
     * @ORM\ManyToOne(targetEntity="App\Company\Entity\Company", inversedBy="userBuildings")
     * @ORM\JoinColumn(name="company_id", referencedColumnName="id", nullable=true)
     * @var \App\Company\Entity\Company|null
     */
    private $company;

    /**
     * @ORM\OneToOne(targetEntity="App\Company\Entity\Company")
     * @var \App\Company\Entity\Company
     */
    private $company2;
}

?>
