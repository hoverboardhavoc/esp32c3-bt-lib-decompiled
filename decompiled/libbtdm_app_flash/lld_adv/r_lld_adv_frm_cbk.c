/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_cbk(int param_1,uint param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 unaff_s4;
  
  if (param_3 != 1) {
    if (param_3 != 0) {
      if (param_3 == 2) {
        return;
      }
      if (param_3 != 4) {
        r_assert_param(param_3,"lld_adv.c",0xb80);
        return;
      }
      param_2 = param_2 & 0xff;
      iVar5 = *(int *)(&lld_adv_env + param_2 * 4);
      if (iVar5 == 0) {
        uVar9 = 0xb5f;
_L1026:
        r_assert_err(0,"lld_adv.c",uVar9);
        return;
      }
      iVar7 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar7 + 0x28) & 4) != 0) &&
         (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
        r_ble_log_internal_x2(0x4040000a,(uint)*(byte *)(iVar5 + 0x89) << 8 | param_2,param_1);
      }
      if (1 < (byte)(*(char *)(iVar5 + 0x89) - 1U)) {
        r_assert_err(0,"lld_adv.c",0xb14);
      }
      if (*(char *)(iVar5 + 0x89) == '\x02') {
        uVar8 = 0;
      }
      else {
        if ((*(char *)(iVar5 + 0x95) == '\0') || (*(int *)(iVar5 + 0x38) != param_1)) {
          r_sch_arb_remove(iVar5,1);
          if ((*(ushort *)(iVar5 + 0x74) & 8) == 0) {
            if ((uint)(*(int *)(iVar5 + 100) << 1) <=
                (param_1 - *(int *)(iVar5 + 0x5c) & 0xfffffffU)) {
              *(char *)(iVar5 + 0x16) = *(char *)(iVar5 + 0x16) + rwip_priority;
              *(undefined4 *)(iVar5 + 0x5c) = *(undefined4 *)(iVar5 + 4);
            }
          }
          else {
            *(char *)(iVar5 + 0x16) = *(char *)(iVar5 + 0x16) + rwip_priority;
          }
          iVar7 = r_sch_arb_insert(iVar5);
          if (iVar7 == 0) goto _L1019;
          if (*(char *)(iVar5 + 0x95) != '\0') {
            return;
          }
          if (*(int *)(iVar5 + 0x58) == -1) {
            uVar9 = 0xb53;
            goto _L1026;
          }
        }
        else {
          r_sch_arb_remove(iVar5 + 0x34,1);
          cVar4 = rwip_priority;
          if ((uint)(*(int *)(iVar5 + 100) << 1) <= (param_1 - *(int *)(iVar5 + 0x60) & 0xfffffffU))
          {
            *(int *)(iVar5 + 0x60) = param_1;
            *(char *)(iVar5 + 0x4a) = *(char *)(iVar5 + 0x4a) + cVar4;
          }
          iVar7 = r_sch_arb_insert(iVar5 + 0x34);
          if (iVar7 == 0) {
_L1019:
            *(undefined1 *)(iVar5 + 0x89) = 0;
            return;
          }
          if (*(int *)(iVar5 + 0x58) == -1) {
            uVar9 = 0xb31;
            goto _L1026;
          }
        }
        uVar8 = 0x3c;
        param_2 = (uint)*(byte *)(iVar5 + 0x87);
      }
      iVar5 = *(int *)(&lld_adv_env + param_2 * 4);
      if (iVar5 != 0) {
        iVar7 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar7 + 0x28) & 4) != 0) &&
           (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
          r_ble_log_internal_x1
                    (0x40000002,
                     (uint)*(byte *)(iVar5 + 0x89) << 0x18 | uVar8 << 0x10 | 0x100 | param_2);
        }
        if ((((*(short *)(iVar5 + 0x24) != 0) && (*(short *)(iVar5 + 0x7e) != 0)) &&
            (*(short *)(iVar5 + 0x24) != *(short *)(iVar5 + 0x7e))) &&
           (((*(ushort *)(iVar5 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar5 + 0x74) & 0x14) == 0x10)
            ))) {
          iVar7 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
          if (iVar7 == 0) {
            r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar5 + 0x7e));
          }
          else {
            r_ble_util_buf_adv_tx_free_in_isr(*(undefined2 *)(iVar5 + 0x7e));
          }
        }
        if (((*(short *)(iVar5 + 0x26) != 0) && (*(short *)(iVar5 + 0x80) != 0)) &&
           ((*(short *)(iVar5 + 0x26) != *(short *)(iVar5 + 0x80) &&
            (((*(ushort *)(iVar5 + 0x74) & 0x12) == 2 ||
             ((*(ushort *)(iVar5 + 0x74) & 0x14) == 0x10)))))) {
          iVar7 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
          if (iVar7 == 0) {
            r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar5 + 0x80));
          }
          else {
            r_ble_util_buf_adv_tx_free_in_isr(*(undefined2 *)(iVar5 + 0x80));
          }
        }
      }
      iVar5 = *(int *)(&lld_adv_env + param_2 * 4);
      if (iVar5 != 0) {
        r_sch_arb_remove(iVar5,0);
        if (*(char *)(iVar5 + 0x95) != '\0') {
          r_sch_arb_remove(iVar5 + 0x34,0);
        }
        if ((*(ushort *)(iVar5 + 0x74) & 8) != 0) {
          r_sch_slice_fg_remove(2);
        }
        puVar6 = (undefined1 *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
        *puVar6 = (char)param_2;
        puVar6[1] = (char)uVar8;
        puVar6[0x35] = 0;
        if ((uVar8 != 0) && (uVar8 = 0, *(short *)(iVar5 + 0x78) != 0)) {
          uVar8 = (uint)*(byte *)(iVar5 + 0x86);
        }
        puVar6[0x38] = (char)uVar8;
        r_ke_msg_send();
        r_ke_free(*(undefined4 *)(&lld_adv_env + param_2 * 4));
        *(undefined4 *)(&lld_adv_env + param_2 * 4) = 0;
      }
      return;
    }
    param_3 = 0;
  }
  param_2 = param_2 & 0xff;
  iVar5 = *(int *)(&lld_adv_env + param_2 * 4);
  bVar3 = false;
  if (iVar5 != 0) {
    bVar1 = *(uint *)(iVar5 + 100) < 0x20;
    bVar2 = g_adv_delay_dis == '\0';
    bVar3 = bVar1 && bVar2;
    iVar7 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar7 + 0x28) & 4) != 0) &&
       (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
      r_ble_log_internal_x1
                (0x40400009,(uint)*(byte *)(iVar5 + 0x89) << 0x10 | param_3 << 8 | param_2);
    }
    if ((param_3 == 0) && (g_ble_ext_config != '\0')) {
      DAT_00016464 = DAT_00016464 + 1;
    }
    if (bVar1 && bVar2) {
      g_adv_delay_dis = '\x01';
      unaff_s4 = *(undefined4 *)(iVar5 + 100);
      uVar8 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
      uVar8 = uVar8 % 9;
      iVar7 = uVar8 << 1;
      if (*(char *)(iVar5 + 0x95) != '\0') {
        if (uVar8 == 0) {
          iVar7 = 1;
        }
        else if (uVar8 == 8) {
          iVar7 = 0xf;
        }
      }
      *(uint *)(iVar5 + 100) = (uint)(iVar7 + *(int *)(iVar5 + 100) * 2) >> 1;
    }
  }
  if ((adv_adv_data_need_to_set[param_2] != '\0') &&
     (((*(ushort *)(iVar5 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar5 + 0x74) & 0x14) == 0x10)))) {
    r_lld_adv_adv_data_set(param_2,*(undefined1 *)(iVar5 + 0x28),*(undefined2 *)(iVar5 + 0x24),1,1);
    *(undefined2 *)(iVar5 + 0x24) = 0;
    adv_adv_data_need_to_set[param_2] = 0;
  }
  if ((adv_scan_rsp_data_need_to_set[param_2] != '\0') &&
     (((*(ushort *)(iVar5 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar5 + 0x74) & 0x14) == 0x10)))) {
    r_lld_adv_scan_rsp_data_set
              (param_2,*(undefined1 *)(iVar5 + 0x2a),*(undefined2 *)(iVar5 + 0x26),1,1);
    *(undefined2 *)(iVar5 + 0x26) = 0;
    adv_scan_rsp_data_need_to_set[param_2] = 0;
  }
  r_lld_adv_frm_isr(param_2,param_1,param_3);
  if ((iVar5 != 0) && (bVar3)) {
    g_adv_delay_dis = '\0';
    *(undefined4 *)(iVar5 + 100) = unaff_s4;
  }
  return;
}

