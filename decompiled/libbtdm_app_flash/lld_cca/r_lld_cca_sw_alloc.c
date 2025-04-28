/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_sw_alloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_cca_sw_alloc(void)

{
  void *pvVar1;
  undefined4 uVar2;
  
  p_lld_cca = (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x2c,*(code **)(_r_osi_funcs_p + 0x78));
  uVar2 = 0;
  if (p_lld_cca != (void *)0x0) {
    memset(p_lld_cca,0,0x2c);
    pvVar1 = p_lld_cca;
    uVar2 = (**(code **)(_r_osi_funcs_p + 0x78))(0x1e0,*(code **)(_r_osi_funcs_p + 0x78));
    *(undefined4 *)((int)pvVar1 + 0x28) = uVar2;
    if (*(void **)((int)p_lld_cca + 0x28) == (void *)0x0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
      uVar2 = 0;
      p_lld_cca = (void *)0x0;
    }
    else {
      memset(*(void **)((int)p_lld_cca + 0x28),0,0x1e0);
      uVar2 = 1;
    }
  }
  return uVar2;
}

