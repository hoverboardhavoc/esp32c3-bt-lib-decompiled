/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_start_schedule_asap
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_start_schedule_asap(int param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  if (*(char *)(iVar2 + 0x95) != '\0') {
    *(uint *)(iVar2 + 0x10) = (uint)*(ushort *)(iVar2 + 0x7a) * 0x1e + 0x271;
  }
  *(undefined4 *)(iVar2 + 4) = param_3;
  *(undefined4 *)(iVar2 + 8) = 0;
  iVar3 = r_sch_arb_insert(iVar2);
  if (iVar3 == 0) {
    r_lld_adv_duration_update(param_1,*(undefined2 *)(param_2 + 0x1a));
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
      iVar3 = r_sch_arb_insert(iVar2 + 0x34);
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
  r_assert_err(0,"lld_adv.c",0xccc);
  return;
}

