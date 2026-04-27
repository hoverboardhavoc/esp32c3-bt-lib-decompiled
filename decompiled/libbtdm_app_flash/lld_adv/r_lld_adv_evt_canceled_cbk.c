/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_evt_canceled_cbk(int param_1)

{
  ushort uVar1;
  char cVar2;
  byte bVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  
  if (param_1 == 0) {
    uVar9 = 0xa42;
  }
  else {
    r_ble_log_internal_x1
              (0x404000ec,CONCAT11(*(undefined1 *)(param_1 + 0x89),*(undefined1 *)(param_1 + 0x87)))
    ;
    if (*(char *)(param_1 + 0x89) != '\0') {
      r_assert_err(0,0x10000,0xa10);
    }
    cVar2 = rwip_priority;
    uVar1 = *(ushort *)(param_1 + 0x74);
    if ((uVar1 & 8) == 0) {
      if ((uint)(*(int *)(param_1 + 100) << 1) <=
          (*(int *)(param_1 + 4) - *(int *)(param_1 + 0x5c) & 0xfffffffU)) {
        *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 4);
        *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + cVar2;
        uVar8 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
        uVar8 = uVar8 % 0x11;
        uVar7 = uVar8 << 1;
        if (*(char *)(param_1 + 0x95) != '\0') {
          if (uVar8 == 0) {
            uVar7 = 1;
          }
          else if (uVar8 == 0x10) {
            uVar7 = 0x1f;
          }
        }
        uVar8 = uVar1 & 8;
        if (g_adv_delay_dis == '\0') {
          uVar8 = uVar7;
        }
        *(uint *)(param_1 + 4) = uVar8 + *(int *)(param_1 + 4) & 0xfffffff;
      }
    }
    else {
      *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + rwip_priority;
    }
    iVar6 = r_sch_arb_insert(param_1);
    if ((iVar6 == 0) || (*(char *)(param_1 + 0x95) != '\0')) {
      return;
    }
    if (*(int *)(param_1 + 0x58) != -1) {
      bVar3 = *(byte *)(param_1 + 0x87);
      uVar7 = (uint)bVar3;
      iVar6 = *(int *)(&lld_adv_env + uVar7 * 4);
      if (iVar6 != 0) {
        r_ble_log_internal_x1(0x400000da,(uint)*(byte *)(iVar6 + 0x89) << 0x18 | uVar7 | 0x3c0100);
        if ((((*(short *)(iVar6 + 0x24) != 0) && (*(short *)(iVar6 + 0x7e) != 0)) &&
            (*(short *)(iVar6 + 0x24) != *(short *)(iVar6 + 0x7e))) &&
           (((*(ushort *)(iVar6 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar6 + 0x74) & 0x14) == 0x10)
            ))) {
          iVar5 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
          if (iVar5 == 0) {
            r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar6 + 0x7e));
          }
          else {
            r_ble_util_buf_adv_tx_free_in_isr();
          }
        }
        if (((*(short *)(iVar6 + 0x26) != 0) && (*(short *)(iVar6 + 0x80) != 0)) &&
           ((*(short *)(iVar6 + 0x26) != *(short *)(iVar6 + 0x80) &&
            (((*(ushort *)(iVar6 + 0x74) & 0x12) == 2 ||
             ((*(ushort *)(iVar6 + 0x74) & 0x14) == 0x10)))))) {
          iVar5 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
          if (iVar5 == 0) {
            r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar6 + 0x80));
          }
          else {
            r_ble_util_buf_adv_tx_free_in_isr();
          }
        }
      }
      iVar6 = *(int *)(&lld_adv_env + uVar7 * 4);
      if (iVar6 != 0) {
        r_sch_arb_remove(iVar6,0);
        if (*(char *)(iVar6 + 0x95) != '\0') {
          r_sch_arb_remove(iVar6 + 0x34,0);
        }
        if ((*(ushort *)(iVar6 + 0x74) & 8) != 0) {
          r_sch_slice_fg_remove(2);
        }
        pbVar4 = (byte *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
        *pbVar4 = bVar3;
        pbVar4[1] = 0x3c;
        pbVar4[0x35] = 0;
        bVar3 = 0;
        if (*(short *)(iVar6 + 0x78) != 0) {
          bVar3 = *(byte *)(iVar6 + 0x86);
        }
        pbVar4[0x38] = bVar3;
        r_ke_msg_send();
        r_ke_free(*(undefined4 *)(&lld_adv_env + uVar7 * 4));
        *(undefined4 *)(&lld_adv_env + uVar7 * 4) = 0;
      }
      return;
    }
    uVar9 = 0xa3b;
  }
  r_assert_err(0,0x10000,uVar9);
  return;
}

