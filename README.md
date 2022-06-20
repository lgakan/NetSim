# NetSim 
Project written in C++ during studies. It's a net simulating production line.

Description:

Production line in factory consists from 3 elements:
- Loading ramps -> Suppling factory with half-products (They are net's sources)
- Workers       -> Half-products processing
- Storehouses   -> Storing Half-products after whole process (They are net's mouth)

There are acceptable links in this technological process:
- Loading ramps <=> Worker (Getting half-products to first stage)
- Worker        <=> Worker (Passing half-products to further processing)
- Worker        <=> Storehouse (Placing finished half-products in storehouses)
