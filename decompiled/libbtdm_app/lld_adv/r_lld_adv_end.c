/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_end(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar3 != 0) {
    (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar3,0,*(code **)(_r_ip_funcs_p + 0x6b8));
    if (*(char *)(iVar3 + 0x95) != '\0') {
      (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar3 + 0x34,0,*(code **)(_r_ip_funcs_p + 0x6b8));
    }
    if ((*(ushort *)(iVar3 + 0x74) & 8) != 0) {
      (**(code **)(_r_ip_funcs_p + 0x724))(2,*(code **)(_r_ip_funcs_p + 0x724));
    }
    if (param_2 != 0) {
      puVar2 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x207,0,0xff,0x3c,*(code **)(_r_modules_funcs_p + 200));
      *puVar2 = (char)param_1;
      puVar2[1] = (char)param_3;
      puVar2[0x35] = 0;
      iVar1 = _r_modules_funcs_p;
      if ((param_3 != 0) && (param_3 = 0, *(short *)(iVar3 + 0x78) != 0)) {
        param_3 = (uint)*(byte *)(iVar3 + 0x86);
      }
      puVar2[0x38] = (char)param_3;
      (**(code **)(iVar1 + 0xe0))(*(code **)(iVar1 + 0xe0));
    }
    (**(code **)(_r_modules_funcs_p + 0x110))
              (*(undefined4 *)(&lld_adv_env + param_1 * 4),*(code **)(_r_modules_funcs_p + 0x110));
    *(undefined4 *)(&lld_adv_env + param_1 * 4) = 0;
  }
  return;
}

