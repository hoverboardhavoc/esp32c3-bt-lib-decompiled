/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_end_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_end_hack(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 != 0) {
    r_ble_log_internal_x1
              (0x400000c0,
               (uint)*(byte *)(iVar1 + 0x89) << 0x18 | param_2 << 8 | param_3 << 0x10 | param_1);
    if ((((*(short *)(iVar1 + 0x24) != 0) && (*(short *)(iVar1 + 0x7e) != 0)) &&
        (*(short *)(iVar1 + 0x24) != *(short *)(iVar1 + 0x7e))) &&
       (((*(ushort *)(iVar1 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar1 + 0x74) & 0x14) == 0x10))))
    {
      iVar3 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar3 == 0) {
        r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar1 + 0x7e));
      }
      else {
        r_ble_util_buf_adv_tx_free_in_isr();
      }
    }
    if (((*(short *)(iVar1 + 0x26) != 0) && (*(short *)(iVar1 + 0x80) != 0)) &&
       ((*(short *)(iVar1 + 0x26) != *(short *)(iVar1 + 0x80) &&
        (((*(ushort *)(iVar1 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar1 + 0x74) & 0x14) == 0x10))))
       )) {
      iVar3 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar3 == 0) {
        r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar1 + 0x80));
      }
      else {
        r_ble_util_buf_adv_tx_free_in_isr();
      }
    }
  }
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 != 0) {
    r_sch_arb_remove(iVar1,0);
    if (*(char *)(iVar1 + 0x95) != '\0') {
      r_sch_arb_remove(iVar1 + 0x34,0);
    }
    if ((*(ushort *)(iVar1 + 0x74) & 8) != 0) {
      r_sch_slice_fg_remove(2);
    }
    if (param_2 != 0) {
      puVar2 = (undefined1 *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
      *puVar2 = (char)param_1;
      puVar2[1] = (char)param_3;
      puVar2[0x35] = 0;
      if ((param_3 != 0) && (param_3 = 0, *(short *)(iVar1 + 0x78) != 0)) {
        param_3 = (uint)*(byte *)(iVar1 + 0x86);
      }
      puVar2[0x38] = (char)param_3;
      r_ke_msg_send();
    }
    r_ke_free(*(undefined4 *)(&lld_adv_env + param_1 * 4));
    *(undefined4 *)(&lld_adv_env + param_1 * 4) = 0;
  }
  return;
}

