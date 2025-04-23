/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_end(int param_1,int param_2,uint param_3)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar2 != 0) {
    r_sch_arb_remove(iVar2,0);
    if (*(char *)(iVar2 + 0x95) != '\0') {
      r_sch_arb_remove(iVar2 + 0x34,0);
    }
    if ((*(ushort *)(iVar2 + 0x74) & 8) != 0) {
      r_sch_slice_fg_remove(2);
    }
    if (param_2 != 0) {
      puVar1 = (undefined1 *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
      *puVar1 = (char)param_1;
      puVar1[1] = (char)param_3;
      puVar1[0x35] = 0;
      if ((param_3 != 0) && (param_3 = 0, *(short *)(iVar2 + 0x78) != 0)) {
        param_3 = (uint)*(byte *)(iVar2 + 0x86);
      }
      puVar1[0x38] = (char)param_3;
      r_ke_msg_send();
    }
    r_ke_free(*(undefined4 *)(&lld_adv_env + param_1 * 4));
    *(undefined4 *)(&lld_adv_env + param_1 * 4) = 0;
  }
  return;
}

