/*
 * Last changed at upstream commit e5c0f7256ecf5b5f8eb28c1793051a6b88f95124
 * https://github.com/espressif/esp32c3-bt-lib/commit/e5c0f7256ecf5b5f8eb28c1793051a6b88f95124
 * Upstream date: 2024-02-04 11:46:50 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(30b57c45)
 * Source: libbtdm_app -> lld_test.o -> r_lld_test_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_test_stop(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined2 uVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar3 = _lld_test_env;
  uVar1 = 0xc;
  if (_lld_test_env != 0) {
    (*_rwip_rf)(1,_rwip_rf);
    _DAT_60031000 = _DAT_60031000 & 0xffffbfff;
    if (*(char *)(iVar3 + 0x2a) == '\0') {
      (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar3,0,*(code **)(_r_ip_funcs_p + 0x6b8));
      _DAT_600310d0 = 0;
      puVar2 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x20a,0,0xff,4,*(code **)(_r_modules_funcs_p + 200));
      *puVar2 = 0;
      uVar4 = 0;
      if (*(char *)(iVar3 + 0x26) == '\0') {
        iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar4 = *(undefined2 *)(iVar3 + 0x4a);
      }
      *(undefined2 *)(puVar2 + 2) = uVar4;
      (**(code **)(_r_modules_funcs_p + 0xe0))(puVar2,*(code **)(_r_modules_funcs_p + 0xe0));
      (**(code **)(_r_ip_funcs_p + 500))(0,*(code **)(_r_ip_funcs_p + 500));
    }
    else if (*(char *)(iVar3 + 0x2a) == '\x01') {
      _DAT_60031000 = _DAT_60031000 | 0x4000000;
      *(undefined1 *)(iVar3 + 0x2a) = 2;
    }
    uVar1 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

