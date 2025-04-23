/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  int iVar2;
  void *__src;
  
  uVar1 = (**(code **)(_r_ip_funcs_p + 0x260))(*(code **)(_r_ip_funcs_p + 0x260));
  if (uVar1 < 10) {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    if ((*(ushort *)(iVar2 + uVar1 * 0x34) >> 7 & 1) != 0) {
      __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                (uVar1 * 0x34 + 0xc8e & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
      memcpy(param_1,__src,6);
      return 0;
    }
  }
  return 2;
}

