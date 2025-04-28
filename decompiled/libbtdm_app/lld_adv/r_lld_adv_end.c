/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  int iVar2;
  undefined1 *puVar3;
  
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar2 != 0) {
    (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar2,0,*(code **)(_r_ip_funcs_p + 0x6b8));
    if (*(char *)(iVar2 + 0x95) != '\0') {
      (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar2 + 0x34,0,*(code **)(_r_ip_funcs_p + 0x6b8));
    }
    if ((*(ushort *)(iVar2 + 0x74) & 8) != 0) {
      (**(code **)(_r_ip_funcs_p + 0x724))(2,*(code **)(_r_ip_funcs_p + 0x724));
    }
    if (param_2 != 0) {
      puVar3 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x207,0,0xff,0x3c,*(code **)(_r_modules_funcs_p + 200));
      *puVar3 = (char)param_1;
      puVar3[1] = (char)param_3;
      puVar3[0x35] = 0;
      iVar1 = _r_modules_funcs_p;
      if ((param_3 != 0) && (param_3 = 0, *(short *)(iVar2 + 0x78) != 0)) {
        param_3 = (uint)*(byte *)(iVar2 + 0x86);
      }
      puVar3[0x38] = (char)param_3;
      (**(code **)(iVar1 + 0xe0))(*(code **)(iVar1 + 0xe0));
    }
    (**(code **)(_r_modules_funcs_p + 0x110))
              (*(undefined4 *)(&lld_adv_env + param_1 * 4),*(code **)(_r_modules_funcs_p + 0x110));
    *(undefined4 *)(&lld_adv_env + param_1 * 4) = 0;
  }
  return;
}

