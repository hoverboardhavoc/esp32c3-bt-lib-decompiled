/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld.o -> r_lld_res_list_local_rpa_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_res_list_local_rpa_get(void *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  void *__src;
  
  uVar1 = (**(code **)(_r_ip_funcs_p + 0x260))(*(code **)(_r_ip_funcs_p + 0x260));
  if ((uVar1 < 10) &&
     (iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc)),
     (*(ushort *)(uVar1 * 0x34 + iVar3) >> 7 & 1) != 0)) {
    __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                              (uVar1 * 0x34 + 0xc8e & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(param_1,__src,6);
    uVar2 = 0;
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}

