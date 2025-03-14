/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_start_schedule_asap
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_start_schedule_asap(int param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  if (*(char *)(iVar2 + 0x95) != '\0') {
    *(uint *)(iVar2 + 0x10) = (uint)*(ushort *)(iVar2 + 0x7a) * 0x1e + 0x271;
  }
  iVar3 = _r_ip_funcs_p;
  *(undefined4 *)(iVar2 + 4) = param_3;
  *(undefined4 *)(iVar2 + 8) = 0;
  iVar3 = (**(code **)(iVar3 + 0x6b0))(iVar2,*(code **)(iVar3 + 0x6b0));
  if (iVar3 == 0) {
    (**(code **)(_r_ip_funcs_p + 0x198))
              (param_1,*(undefined2 *)(param_2 + 0x1a),*(code **)(_r_ip_funcs_p + 0x198));
    *(undefined1 *)(iVar2 + 0x89) = 0;
    *(int *)(iVar2 + 0x5c) = *(int *)(iVar2 + 4);
    bVar1 = rwip_priority;
    if (*(char *)(iVar2 + 0x95) != '\0') {
      if (*(int *)(iVar2 + 0x58) != -1) {
        *(int *)(iVar2 + 0x40) = *(int *)(iVar2 + 0x58);
        *(ushort *)(iVar2 + 0x48) = bVar1 & 0xf | 0xa000;
      }
      *(uint *)(iVar2 + 0x38) =
           (uint)*(byte *)(iVar2 + 0x8f) * *(int *)(iVar2 + 100) * 2 + *(int *)(iVar2 + 4) &
           0xfffffff;
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar2 + 0x34,*(code **)(_r_ip_funcs_p + 0x6b0));
      if (iVar3 == 0) {
        *(undefined4 *)(iVar2 + 0x60) = *(undefined4 *)(iVar2 + 0x38);
      }
      else {
        *(undefined1 *)(iVar2 + 0x95) = 0;
        *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar2 + 0x44);
      }
    }
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00015b22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0xccc);
  return;
}

