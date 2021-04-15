program matriz_vetor_f
    implicit none

    character(len = 32) :: arg
    integer :: n, func
    real(8) :: inicio, fim
    real(8), dimension (:,:), allocatable :: matriz
    real(8), dimension (:), allocatable :: vetor
    real(8), dimension (:), allocatable :: resultado


    call getarg (1, arg)    
    read(arg, "(I10)") n


    call getarg (2, arg)    
    read(arg, "(I1)") func


    allocate (matriz(n, n))
    allocate (vetor(n))
    allocate (resultado(n))

    call random_seed()

    call gerar_vetor (vetor, n)
    call gerar_matriz (matriz, n)

    if (func == 1) then
        call cpu_time(inicio) 
        call produto_linha_coluna (vetor, matriz, resultado, n)
        call cpu_time(fim) 
    else if (func == 0) then
        call cpu_time(inicio) 
        call produto_coluna_linha (vetor, matriz, resultado, n)
        call cpu_time(fim) 
    else
        CALL EXIT(0)
    end if


    deallocate (matriz)
    deallocate (vetor)
    deallocate (resultado)

    print *, n, ";", (fim - inicio)

    contains

    subroutine gerar_vetor (vetor, n)
        implicit none

        real(8), dimension (:) :: vetor
        integer :: n, linha
        real(8) :: valor
        do linha = 1, n
            call random_number(valor)
            vetor(linha) = valor * (n + 1)
        end do 
    end

    subroutine gerar_matriz (matriz, n)
        implicit none

        real(8), dimension (:,:) :: matriz
        integer :: n, linha, coluna
        real(8) :: valor

        do linha = 1, n
            do coluna = 1, n
                call random_number(valor)
                matriz(linha, coluna) = valor * (n + 1)
            end do
        end do 
    end

    subroutine zerar_resultado (vetor, n)
        implicit none

        real(8), dimension (:) :: vetor
        integer :: n, linha
        real(8) :: number
        do linha = 1, n
            vetor(linha) = 0
        end do 
    end

    subroutine produto_coluna_linha (vetor, matriz, resultado, n)
        implicit none

        real(8), dimension (:) :: vetor
        real(8), dimension (:, :) :: matriz
        real(8), dimension (:) :: resultado
        integer :: linha, coluna, n

        call zerar_resultado (resultado, n)

        do coluna=1, n
            do linha=1, n
                resultado(linha) = resultado(linha) +  matriz(linha, coluna) * vetor(coluna);
            end do
        end do
    end

    subroutine produto_linha_coluna (vetor, matriz, resultado, n)
        implicit none

        real(8), dimension (:) :: vetor
        real(8), dimension (:, :) :: matriz
        real(8), dimension (:) :: resultado
        integer :: linha, coluna, n

        call zerar_resultado (resultado, n)

        do linha=1, n
            do coluna=1, n
                resultado(linha) = resultado(linha) +  matriz(linha, coluna) * vetor(coluna);
            end do
        end do
    end

end program matriz_vetor_f
