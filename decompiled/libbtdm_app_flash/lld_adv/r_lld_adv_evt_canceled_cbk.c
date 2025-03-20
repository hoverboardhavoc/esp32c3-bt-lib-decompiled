/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
  byte *pbVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  byte bVar7;
  
  if (param_1 == 0) {
    uVar6 = 0x998;
  }
  else {
    if (*(char *)(param_1 + 0x89) != '\0') {
      r_assert_err(0,"lld_adv.c",0x966);
    }
    cVar1 = rwip_priority;
    if ((*(ushort *)(param_1 + 0x74) & 8) == 0) {
      if ((uint)(*(int *)(param_1 + 100) << 1) <=
          (*(int *)(param_1 + 4) - *(int *)(param_1 + 0x5c) & 0xfffffffU)) {
        *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 4);
        *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + cVar1;
        uVar5 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
        uVar5 = uVar5 % 0x11;
        iVar4 = uVar5 << 1;
        if (*(char *)(param_1 + 0x95) != '\0') {
          if (uVar5 == 0) {
            iVar4 = 1;
          }
          else if (uVar5 == 0x10) {
            iVar4 = 0x1f;
          }
        }
        if (g_adv_delay_dis != '\0') {
          iVar4 = 0;
        }
        *(uint *)(param_1 + 4) = iVar4 + *(int *)(param_1 + 4) & 0xfffffff;
      }
    }
    else {
      *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + rwip_priority;
    }
    iVar4 = r_sch_arb_insert(param_1);
    if ((iVar4 == 0) || (*(char *)(param_1 + 0x95) != '\0')) {
      return;
    }
    if (*(int *)(param_1 + 0x58) != -1) {
      bVar7 = *(byte *)(param_1 + 0x87);
      iVar4 = *(int *)(&lld_adv_env + (uint)bVar7 * 4);
      if (iVar4 != 0) {
        if ((((*(short *)(iVar4 + 0x24) != 0) && (*(short *)(iVar4 + 0x7e) != 0)) &&
            (*(short *)(iVar4 + 0x24) != *(short *)(iVar4 + 0x7e))) &&
           (((*(ushort *)(iVar4 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar4 + 0x74) & 0x14) == 0x10)
            ))) {
          iVar3 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
          if (iVar3 == 0) {
            r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar4 + 0x7e));
          }
          else {
            r_ble_util_buf_adv_tx_free_in_isr(*(undefined2 *)(iVar4 + 0x7e));
          }
        }
        if (((*(short *)(iVar4 + 0x26) != 0) && (*(short *)(iVar4 + 0x80) != 0)) &&
           ((*(short *)(iVar4 + 0x26) != *(short *)(iVar4 + 0x80) &&
            (((*(ushort *)(iVar4 + 0x74) & 0x12) == 2 ||
             ((*(ushort *)(iVar4 + 0x74) & 0x14) == 0x10)))))) {
          iVar3 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
          if (iVar3 == 0) {
            r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar4 + 0x80));
          }
          else {
            r_ble_util_buf_adv_tx_free_in_isr(*(undefined2 *)(iVar4 + 0x80));
          }
        }
      }
      iVar3 = (uint)bVar7 * 4;
      iVar4 = *(int *)(&lld_adv_env + iVar3);
      if (iVar4 != 0) {
        r_sch_arb_remove(iVar4,0);
        if (*(char *)(iVar4 + 0x95) != '\0') {
          r_sch_arb_remove(iVar4 + 0x34,0);
        }
        if ((*(ushort *)(iVar4 + 0x74) & 8) != 0) {
          r_sch_slice_fg_remove(2);
        }
        pbVar2 = (byte *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
        *pbVar2 = bVar7;
        pbVar2[1] = 0x3c;
        pbVar2[0x35] = 0;
        bVar7 = 0;
        if (*(short *)(iVar4 + 0x78) != 0) {
          bVar7 = *(byte *)(iVar4 + 0x86);
        }
        pbVar2[0x38] = bVar7;
        r_ke_msg_send();
        r_ke_free(*(undefined4 *)(&lld_adv_env + iVar3));
        *(undefined4 *)(&lld_adv_env + iVar3) = 0;
      }
      return;
    }
    uVar6 = 0x991;
  }
  r_assert_err(0,"lld_adv.c",uVar6);
  return;
}

