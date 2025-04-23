/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_end(void)

{
  bool bVar1;
  undefined1 uVar2;
  byte bVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  do {
    iVar4 = iVar7 * 4;
    iVar6 = *(int *)(_lld_init_env + iVar4);
    if (iVar6 != 0) {
      if (*(char *)(iVar6 + 0x31) == '\0') {
        (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar6,0,*(code **)(_r_ip_funcs_p + 0x6b8));
        (**(code **)(_r_ip_funcs_p + 0x718))(1,*(code **)(_r_ip_funcs_p + 0x718));
        (**(code **)(_r_modules_funcs_p + 0x110))
                  (*(undefined4 *)(_lld_init_env + iVar4),*(code **)(_r_modules_funcs_p + 0x110));
        iVar6 = _lld_init_env;
        *(undefined4 *)(iVar4 + _lld_init_env) = 0;
        *(byte *)(iVar6 + 0x2b) = ~(byte)(1 << iVar7) & *(byte *)(iVar6 + 0x2b);
      }
      else if (*(char *)(iVar6 + 0x31) == '\x01') {
        bVar3 = *(byte *)(iVar6 + 0x52);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)((uint)bVar3 * 0x5a + 0x20 + iVar4) = 1;
        _DAT_60031000 = _DAT_60031000 | 0x1000000;
        *(undefined1 *)(iVar6 + 0x31) = 2;
      }
    }
    bVar1 = iVar7 != 1;
    iVar7 = 1;
  } while (bVar1);
  if (*(char *)(_lld_init_env + 0x2b) == '\0') {
    if (*(int *)(_lld_init_env + 8) == 0) {
      puVar5 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x209,0,0xff,0x38,*(code **)(_r_modules_funcs_p + 200));
      uVar2 = *(undefined1 *)(_lld_init_env + 0x2c);
      puVar5[1] = 0;
      *puVar5 = uVar2;
    }
    (**(code **)(_r_modules_funcs_p + 0xe0))(*(code **)(_r_modules_funcs_p + 0xe0));
    (**(code **)(_r_modules_funcs_p + 0x110))(_lld_init_env,*(code **)(_r_modules_funcs_p + 0x110));
    _lld_init_env = 0;
  }
  return;
}

