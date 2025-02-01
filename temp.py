def min_operations_to_transform(N, M, operations):
    # Initialize the sequence
    x = [0] * N
    
    # Arrays to track ranges affected by operation 1 and 2
    op1_ranges = []
    op2_ranges = []
    
    # Process each operation
    for L, R in operations:
        # Convert to zero-based index
        L -= 1
        R -= 1
        
        # Check if this operation can help us reach our goal
        # We need to cover the entire range [0, N-1] with some combination of ops
        op1_ranges.append((L, R))
        op2_ranges.append((L, R))
    
    # Determine if we can achieve the goal
    # We need to check if we can cover the entire range [0, N-1] with some combination of ops
    # Sort ranges by start point
    op1_ranges.sort()
    op2_ranges.sort(key=lambda x: (-x[1], x[0]))
    
    # Try to cover the entire range with op1
    covered_by_op1 = [False] * N
    current_end = -1
    for L, R in op1_ranges:
        if L > current_end + 1:
            break
        current_end = max(current_end, R)
        for j in range(L, R + 1):
            covered_by_op1[j] = True
    
    # Try to cover the uncovered parts with op2
    covered_by_op2 = [False] * N
    current_start = N
    for L, R in op2_ranges:
        if R < current_start - 1:
            break
        current_start = min(current_start, L)
        for j in range(0, L):
            covered_by_op2[j] = True
        for j in range(R + 1, N):
            covered_by_op2[j] = True
    
    # Check if all positions are covered
    all_covered = all(covered_by_op1[i] or covered_by_op2[i] for i in range(N))
    
    if not all_covered:
        return -1
    
    # Construct the result
    result_ops = []
    current_state = [0] * N
    for L, R in operations:
        L -= 1
        R -= 1
        if not any(current_state[L:R+1]):
            # Perform op1 if needed
            result_ops.append(1)
            for j in range(L, R + 1):
                current_state[j] = 1
        else:
            # Perform op0 if no change needed
            result_ops.append(0)
    
    # Ensure all are 1s
    if not all(current_state):
        # Perform remaining ops if needed
        for i in range(M):
            L, R = operations[i]
            L -= 1
            R -= 1
            if not any(current_state[L:R+1]):
                result_ops[i] = 1
                for j in range(L, R + 1):
                    current_state[j] = 1
    
    # Count the number of ops performed
    K = sum(result_ops)
    
    return f"{K}\n{' '.join(map(str, result_ops))}"

# Example usage
N = 5
M = 4
operations = [(2, 4), (3, 5), (1, 4), (2, 5)]
print(min_operations_to_transform(N, M, operations))



