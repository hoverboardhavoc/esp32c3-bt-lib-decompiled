/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
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
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  undefined4 uVar7;
  uint uVar8;
  uint unaff_s3;
  
  if (param_3 != 1) {
    if (param_3 != 0) {
      if (param_3 == 2) {
        return;
      }
      if (param_3 != 4) {
        r_assert_param(param_3,"lld_adv.c",0xb5a);
        return;
      }
      param_2 = param_2 & 0xff;
      iVar2 = *(int *)(&lld_adv_env + param_2 * 4);
      if (iVar2 == 0) {
        uVar7 = 0xb39;
_L986:
        r_assert_err(0,"lld_adv.c",uVar7);
        return;
      }
      if (1 < (byte)(*(char *)(iVar2 + 0x89) - 1U)) {
        r_assert_err(0,"lld_adv.c",0xaee);
      }
      if (*(char *)(iVar2 + 0x89) == '\x02') {
        cVar6 = '\0';
      }
      else {
        if ((*(char *)(iVar2 + 0x95) == '\0') || (*(int *)(iVar2 + 0x38) != param_1)) {
          r_sch_arb_remove(iVar2,1);
          if ((*(ushort *)(iVar2 + 0x74) & 8) == 0) {
            if ((uint)(*(int *)(iVar2 + 100) << 1) <=
                (param_1 - *(int *)(iVar2 + 0x5c) & 0xfffffffU)) {
              *(char *)(iVar2 + 0x16) = *(char *)(iVar2 + 0x16) + rwip_priority;
              *(undefined4 *)(iVar2 + 0x5c) = *(undefined4 *)(iVar2 + 4);
            }
          }
          else {
            *(char *)(iVar2 + 0x16) = *(char *)(iVar2 + 0x16) + rwip_priority;
          }
          iVar5 = r_sch_arb_insert(iVar2);
          if (iVar5 == 0) goto _L979;
          if (*(char *)(iVar2 + 0x95) != '\0') {
            return;
          }
          if (*(int *)(iVar2 + 0x58) == -1) {
            uVar7 = 0xb2d;
            goto _L986;
          }
        }
        else {
          r_sch_arb_remove(iVar2 + 0x34,1);
          cVar6 = rwip_priority;
          if ((uint)(*(int *)(iVar2 + 100) << 1) <= (param_1 - *(int *)(iVar2 + 0x60) & 0xfffffffU))
          {
            *(int *)(iVar2 + 0x60) = param_1;
            *(char *)(iVar2 + 0x4a) = *(char *)(iVar2 + 0x4a) + cVar6;
          }
          iVar5 = r_sch_arb_insert(iVar2 + 0x34);
          if (iVar5 == 0) {
_L979:
            *(undefined1 *)(iVar2 + 0x89) = 0;
            return;
          }
          if (*(int *)(iVar2 + 0x58) == -1) {
            uVar7 = 0xb0b;
            goto _L986;
          }
        }
        cVar6 = '<';
        param_2 = (uint)*(byte *)(iVar2 + 0x87);
      }
      iVar2 = *(int *)(&lld_adv_env + param_2 * 4);
      if (iVar2 != 0) {
        if ((((*(short *)(iVar2 + 0x24) != 0) && (*(short *)(iVar2 + 0x7e) != 0)) &&
            (*(short *)(iVar2 + 0x24) != *(short *)(iVar2 + 0x7e))) &&
           (((*(ushort *)(iVar2 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar2 + 0x74) & 0x14) == 0x10)
            ))) {
          iVar5 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
          if (iVar5 == 0) {
            r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar2 + 0x7e));
          }
          else {
            r_ble_util_buf_adv_tx_free_in_isr(*(undefined2 *)(iVar2 + 0x7e));
          }
        }
        if (((*(short *)(iVar2 + 0x26) != 0) && (*(short *)(iVar2 + 0x80) != 0)) &&
           ((*(short *)(iVar2 + 0x26) != *(short *)(iVar2 + 0x80) &&
            (((*(ushort *)(iVar2 + 0x74) & 0x12) == 2 ||
             ((*(ushort *)(iVar2 + 0x74) & 0x14) == 0x10)))))) {
          iVar5 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
          if (iVar5 == 0) {
            r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar2 + 0x80));
          }
          else {
            r_ble_util_buf_adv_tx_free_in_isr(*(undefined2 *)(iVar2 + 0x80));
          }
        }
      }
      iVar2 = *(int *)(&lld_adv_env + param_2 * 4);
      if (iVar2 != 0) {
        r_sch_arb_remove(iVar2,0);
        if (*(char *)(iVar2 + 0x95) != '\0') {
          r_sch_arb_remove(iVar2 + 0x34,0);
        }
        if ((*(ushort *)(iVar2 + 0x74) & 8) != 0) {
          r_sch_slice_fg_remove(2);
        }
        puVar3 = (undefined1 *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
        *puVar3 = (char)param_2;
        puVar3[1] = cVar6;
        puVar3[0x35] = 0;
        if ((cVar6 != '\0') && (cVar6 = '\0', *(short *)(iVar2 + 0x78) != 0)) {
          cVar6 = *(char *)(iVar2 + 0x86);
        }
        puVar3[0x38] = cVar6;
        r_ke_msg_send();
        r_ke_free(*(undefined4 *)(&lld_adv_env + param_2 * 4));
        *(undefined4 *)(&lld_adv_env + param_2 * 4) = 0;
      }
      return;
    }
    param_3 = 0;
  }
  param_2 = param_2 & 0xff;
  iVar2 = *(int *)(&lld_adv_env + param_2 * 4);
  bVar1 = false;
  if (iVar2 == 0) goto _L926;
  uVar8 = *(uint *)(iVar2 + 100);
  if ((uVar8 < 0x20) && (g_adv_delay_dis == '\0')) {
    bVar1 = true;
    if (param_3 == 0) goto _L936;
  }
  else {
    bVar1 = false;
    if (param_3 != 0) goto _L926;
    bVar1 = false;
_L936:
    if (g_qa_test_config != '\0') {
      DAT_00015e7c = DAT_00015e7c + 1;
    }
    if (!bVar1) goto _L926;
  }
  g_adv_delay_dis = '\x01';
  uVar4 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  uVar4 = uVar4 % 9;
  iVar5 = uVar4 << 1;
  if (*(char *)(iVar2 + 0x95) != '\0') {
    if (uVar4 == 0) {
      iVar5 = 1;
    }
    else if (uVar4 == 8) {
      iVar5 = 0xf;
    }
  }
  bVar1 = true;
  *(uint *)(iVar2 + 100) = (uint)(iVar5 + *(int *)(iVar2 + 100) * 2) >> 1;
  unaff_s3 = uVar8;
_L926:
  if ((adv_adv_data_need_to_set[param_2] != '\0') &&
     (((*(ushort *)(iVar2 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar2 + 0x74) & 0x14) == 0x10)))) {
    r_lld_adv_adv_data_set(param_2,*(undefined1 *)(iVar2 + 0x28),*(undefined2 *)(iVar2 + 0x24),1,1);
    *(undefined2 *)(iVar2 + 0x24) = 0;
    adv_adv_data_need_to_set[param_2] = 0;
  }
  if ((adv_scan_rsp_data_need_to_set[param_2] != '\0') &&
     (((*(ushort *)(iVar2 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar2 + 0x74) & 0x14) == 0x10)))) {
    r_lld_adv_scan_rsp_data_set
              (param_2,*(undefined1 *)(iVar2 + 0x2a),*(undefined2 *)(iVar2 + 0x26),1,1);
    *(undefined2 *)(iVar2 + 0x26) = 0;
    adv_scan_rsp_data_need_to_set[param_2] = 0;
  }
  r_lld_adv_frm_isr(param_2,param_1,param_3);
  if ((iVar2 != 0) && (bVar1)) {
    g_adv_delay_dis = '\0';
    *(uint *)(iVar2 + 100) = unaff_s3;
  }
  return;
}

