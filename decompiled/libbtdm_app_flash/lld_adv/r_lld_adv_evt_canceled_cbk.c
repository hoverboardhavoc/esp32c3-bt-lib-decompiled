/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_evt_canceled_cbk(int param_1)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  
  if (param_1 == 0) {
    uVar8 = 0x9ac;
  }
  else {
    iVar5 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar5 + 0x28) & 4) != 0) &&
       (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
      r_ble_log_internal_x1
                (0x4040000b,
                 CONCAT11(*(undefined1 *)(param_1 + 0x89),*(undefined1 *)(param_1 + 0x87)));
    }
    if (*(char *)(param_1 + 0x89) != '\0') {
      r_assert_err(0,0x10000,0x97a);
    }
    cVar1 = rwip_priority;
    if ((*(ushort *)(param_1 + 0x74) & 8) == 0) {
      if ((uint)(*(int *)(param_1 + 100) << 1) <=
          (*(int *)(param_1 + 4) - *(int *)(param_1 + 0x5c) & 0xfffffffU)) {
        *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 4);
        *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + cVar1;
        uVar6 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
        uVar7 = uVar6 % 0x11 << 1;
        if (*(char *)(param_1 + 0x95) != '\0') {
          if (uVar7 < 0x20) {
            if (uVar6 % 0x11 == 0) {
              uVar7 = 1;
            }
          }
          else {
            uVar7 = 0x1f;
          }
        }
        *(uint *)(param_1 + 4) =
             (uVar7 & -(uint)(g_adv_delay_dis == '\0')) + *(int *)(param_1 + 4) & 0xfffffff;
      }
    }
    else {
      *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + rwip_priority;
    }
    iVar5 = r_sch_arb_insert(param_1);
    if ((iVar5 == 0) || (*(char *)(param_1 + 0x95) != '\0')) {
      return;
    }
    if (*(int *)(param_1 + 0x58) != -1) {
      bVar2 = *(byte *)(param_1 + 0x87);
      uVar6 = (uint)bVar2;
      iVar5 = *(int *)(&lld_adv_env + uVar6 * 4);
      if (iVar5 != 0) {
        iVar4 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar4 + 0x28) & 4) != 0) &&
           (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
          r_ble_log_internal_x1(0x40000002,(uint)*(byte *)(iVar5 + 0x89) << 0x18 | uVar6 | 0x3c0100)
          ;
        }
        if ((((*(short *)(iVar5 + 0x24) != 0) && (*(short *)(iVar5 + 0x7e) != 0)) &&
            (*(short *)(iVar5 + 0x24) != *(short *)(iVar5 + 0x7e))) &&
           (((*(ushort *)(iVar5 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar5 + 0x74) & 0x14) == 0x10)
            ))) {
          iVar4 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
          if (iVar4 == 0) {
            r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar5 + 0x7e));
          }
          else {
            r_ble_util_buf_adv_tx_free_in_isr();
          }
        }
        if (((*(short *)(iVar5 + 0x26) != 0) && (*(short *)(iVar5 + 0x80) != 0)) &&
           ((*(short *)(iVar5 + 0x26) != *(short *)(iVar5 + 0x80) &&
            (((*(ushort *)(iVar5 + 0x74) & 0x12) == 2 ||
             ((*(ushort *)(iVar5 + 0x74) & 0x14) == 0x10)))))) {
          iVar4 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
          if (iVar4 == 0) {
            r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar5 + 0x80));
          }
          else {
            r_ble_util_buf_adv_tx_free_in_isr();
          }
        }
      }
      iVar5 = *(int *)(&lld_adv_env + uVar6 * 4);
      if (iVar5 != 0) {
        r_sch_arb_remove(iVar5,0);
        if (*(char *)(iVar5 + 0x95) != '\0') {
          r_sch_arb_remove(iVar5 + 0x34,0);
        }
        if ((*(ushort *)(iVar5 + 0x74) & 8) != 0) {
          r_sch_slice_fg_remove(2);
        }
        pbVar3 = (byte *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
        *pbVar3 = bVar2;
        pbVar3[1] = 0x3c;
        pbVar3[0x35] = 0;
        bVar2 = 0;
        if (*(short *)(iVar5 + 0x78) != 0) {
          bVar2 = *(byte *)(iVar5 + 0x86);
        }
        pbVar3[0x38] = bVar2;
        r_ke_msg_send();
        r_ke_free(*(undefined4 *)(&lld_adv_env + uVar6 * 4));
        *(undefined4 *)(&lld_adv_env + uVar6 * 4) = 0;
      }
      return;
    }
    uVar8 = 0x9a5;
  }
  r_assert_err(0,0x10000,uVar8);
  return;
}

