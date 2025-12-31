/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_cbk(int param_1,uint param_2,uint param_3)

{
  bool bVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  bool bVar6;
  bool bVar7;
  char cVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined1 *puVar12;
  int iVar13;
  undefined4 uVar14;
  uint uVar15;
  byte bVar16;
  int iVar17;
  byte bVar18;
  int iVar19;
  undefined4 uStack_58;
  
  if (param_3 == 2) {
    return;
  }
  if (param_3 < 3) {
    param_2 = param_2 & 0xff;
    if (param_3 != 0) {
      param_3 = 1;
    }
    iVar17 = *(int *)(&lld_adv_env + param_2 * 4);
    bVar7 = false;
    if (iVar17 == 0) {
_L955:
      if ((adv_adv_data_need_to_set[param_2] != '\0') &&
         (((*(ushort *)(iVar17 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar17 + 0x74) & 0x14) == 0x10)
          ))) {
        r_lld_adv_adv_data_set_hack
                  (param_2,*(undefined1 *)(iVar17 + 0x28),*(undefined2 *)(iVar17 + 0x24),1,1);
        *(undefined2 *)(iVar17 + 0x24) = 0;
        adv_adv_data_need_to_set[param_2] = 0;
      }
      if ((adv_scan_rsp_data_need_to_set[param_2] != '\0') &&
         (((*(ushort *)(iVar17 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar17 + 0x74) & 0x14) == 0x10)
          ))) {
        r_lld_adv_scan_rsp_data_set_hack
                  (param_2,*(undefined1 *)(iVar17 + 0x2a),*(undefined2 *)(iVar17 + 0x26),1,1);
        *(undefined2 *)(iVar17 + 0x26) = 0;
        adv_scan_rsp_data_need_to_set[param_2] = 0;
      }
      r_lld_adv_frm_isr(param_2,param_1,param_3);
      if ((iVar17 != 0) && (bVar7)) {
        g_adv_delay_dis = '\0';
        *(undefined4 *)(iVar17 + 100) = uStack_58;
      }
      return;
    }
    bVar1 = *(uint *)(iVar17 + 100) < 0x20;
    bVar6 = g_adv_delay_dis == '\0';
    bVar7 = bVar1 && bVar6;
    bVar18 = *(byte *)(iVar17 + 0x87);
    iVar13 = r_emi_get_mem_addr_by_offset(0x400);
    iVar10 = (uint)bVar18 * 0x5a;
    bVar18 = 1;
    uVar2 = *(ushort *)(iVar13 + iVar10 + 4);
    iVar13 = r_emi_get_mem_addr_by_offset(0x400);
    uVar9 = (uVar2 & 0xc) << 2 | *(ushort *)(iVar13 + iVar10 + 4) & 3;
    iVar13 = r_emi_get_mem_addr_by_offset(0x400);
    uVar3 = *(undefined2 *)(iVar10 + 0xe + iVar13);
    iVar13 = r_emi_get_mem_addr_by_offset(0x400);
    uVar4 = *(undefined2 *)(iVar10 + 0xc + iVar13);
    uVar11 = *(uint *)(iVar17 + 4) * 0x271;
    uVar15 = *(int *)(iVar17 + 8) + uVar11;
    uVar11 = ((uint)(uVar15 < uVar11) + (int)((ulonglong)*(uint *)(iVar17 + 4) * 0x271 >> 0x20)) *
             -0x80000000 | uVar15 >> 1;
    if ((*(ushort *)(iVar17 + 0x74) & 0x10) == 0) {
      bVar18 = *(byte *)(iVar17 + 0x92);
    }
    bVar16 = 0;
    uVar15 = 0x25;
    do {
      do {
        if (((bVar18 <= bVar16) ||
            (r_ble_log_internal_x4
                       (0x40400000,CONCAT22(uVar3,uVar4),uVar11,*(undefined1 *)(iVar17 + 0x86),
                        (uint)*(byte *)(iVar17 + 0x87) | param_3 << 8 | uVar15 << 0x10 |
                        uVar9 << 0x18), (*(ushort *)(iVar17 + 0x74) & 0x10) != 0)) || (bVar16 != 0))
        {
          if ((param_3 == 0) && (g_ble_ext_config != '\0')) {
            DAT_00016594 = DAT_00016594 + 1;
          }
          if (bVar1 && bVar6) {
            g_adv_delay_dis = '\x01';
            uStack_58 = *(undefined4 *)(iVar17 + 100);
            uVar9 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
            uVar9 = uVar9 % 9;
            iVar10 = uVar9 << 1;
            if (*(char *)(iVar17 + 0x95) != '\0') {
              if (uVar9 == 0) {
                iVar10 = 1;
              }
              else if (uVar9 == 8) {
                iVar10 = 0xf;
              }
            }
            *(uint *)(iVar17 + 100) = (uint)(*(int *)(iVar17 + 100) * 2 + iVar10) >> 1;
          }
          goto _L955;
        }
        iVar13 = ((uint)*(byte *)(iVar17 + 0x87) * 9 & 0xff) * 0xe;
        iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
        bVar16 = 1;
      } while ((*(ushort *)(iVar13 + 6 + iVar10) & 0x1000) == 0);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar19 = iVar13 + 8;
      uVar15 = *(ushort *)(iVar10 + iVar19) & 0x3f;
      iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar9 = *(ushort *)(iVar10 + iVar13 + 10) >> 5 & 7;
      uVar9 = uVar9 | uVar9 << 4;
      iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar2 = *(ushort *)(iVar10 + iVar13 + 10);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar5 = *(ushort *)(iVar10 + iVar19);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar13 = 300;
      if ((*(ushort *)(iVar10 + iVar19) & 0x80) == 0) {
        iVar13 = 0x1e;
      }
      bVar16 = 1;
      uVar11 = uVar11 + (((uVar2 & 0x1f) << 8 | (uint)(uVar5 >> 8)) * iVar13 & 0xffff);
    } while( true );
  }
  if (param_3 != 4) {
    r_assert_param(param_3,0x10000,0xbb0);
    return;
  }
  param_2 = param_2 & 0xff;
  iVar17 = *(int *)(&lld_adv_env + param_2 * 4);
  if (iVar17 == 0) {
    uVar14 = 0xb8f;
_L1024:
    r_assert_err(0,0x10000,uVar14);
    return;
  }
  r_ble_log_internal_x2(0x404000d0,(uint)*(byte *)(iVar17 + 0x89) << 8 | param_2);
  if (1 < (byte)(*(char *)(iVar17 + 0x89) - 1U)) {
    r_assert_err(0,0x10000,0xb44);
  }
  if (*(char *)(iVar17 + 0x89) == '\x02') {
    uVar9 = 0;
  }
  else {
    if ((*(char *)(iVar17 + 0x95) == '\0') || (*(int *)(iVar17 + 0x38) != param_1)) {
      r_sch_arb_remove(iVar17,1);
      if ((*(ushort *)(iVar17 + 0x74) & 8) == 0) {
        if ((uint)(*(int *)(iVar17 + 100) << 1) <= (param_1 - *(int *)(iVar17 + 0x5c) & 0xfffffffU))
        {
          *(char *)(iVar17 + 0x16) = *(char *)(iVar17 + 0x16) + rwip_priority;
          *(undefined4 *)(iVar17 + 0x5c) = *(undefined4 *)(iVar17 + 4);
        }
      }
      else {
        *(char *)(iVar17 + 0x16) = *(char *)(iVar17 + 0x16) + rwip_priority;
      }
      iVar10 = r_sch_arb_insert(iVar17);
      if (iVar10 == 0) goto _L1017;
      if (*(char *)(iVar17 + 0x95) != '\0') {
        return;
      }
      if (*(int *)(iVar17 + 0x58) == -1) {
        uVar14 = 0xb83;
        goto _L1024;
      }
    }
    else {
      r_sch_arb_remove(iVar17 + 0x34,1);
      cVar8 = rwip_priority;
      if ((uint)(*(int *)(iVar17 + 100) << 1) <= (param_1 - *(int *)(iVar17 + 0x60) & 0xfffffffU)) {
        *(int *)(iVar17 + 0x60) = param_1;
        *(char *)(iVar17 + 0x4a) = *(char *)(iVar17 + 0x4a) + cVar8;
      }
      iVar10 = r_sch_arb_insert(iVar17 + 0x34);
      if (iVar10 == 0) {
_L1017:
        *(undefined1 *)(iVar17 + 0x89) = 0;
        return;
      }
      if (*(int *)(iVar17 + 0x58) == -1) {
        uVar14 = 0xb61;
        goto _L1024;
      }
    }
    param_2 = (uint)*(byte *)(iVar17 + 0x87);
    uVar9 = 0x3c;
  }
  iVar17 = *(int *)(&lld_adv_env + param_2 * 4);
  if (iVar17 != 0) {
    r_ble_log_internal_x1
              (0x400000c0,(uint)*(byte *)(iVar17 + 0x89) << 0x18 | uVar9 << 0x10 | 0x100 | param_2);
    if ((((*(short *)(iVar17 + 0x24) != 0) && (*(short *)(iVar17 + 0x7e) != 0)) &&
        (*(short *)(iVar17 + 0x24) != *(short *)(iVar17 + 0x7e))) &&
       (((*(ushort *)(iVar17 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar17 + 0x74) & 0x14) == 0x10)))
       ) {
      iVar10 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar10 == 0) {
        r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar17 + 0x7e));
      }
      else {
        r_ble_util_buf_adv_tx_free_in_isr();
      }
    }
    if (((*(short *)(iVar17 + 0x26) != 0) && (*(short *)(iVar17 + 0x80) != 0)) &&
       ((*(short *)(iVar17 + 0x26) != *(short *)(iVar17 + 0x80) &&
        (((*(ushort *)(iVar17 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar17 + 0x74) & 0x14) == 0x10))
        )))) {
      iVar10 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar10 == 0) {
        r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar17 + 0x80));
      }
      else {
        r_ble_util_buf_adv_tx_free_in_isr();
      }
    }
  }
  iVar17 = *(int *)(&lld_adv_env + param_2 * 4);
  if (iVar17 != 0) {
    r_sch_arb_remove(iVar17,0);
    if (*(char *)(iVar17 + 0x95) != '\0') {
      r_sch_arb_remove(iVar17 + 0x34,0);
    }
    if ((*(ushort *)(iVar17 + 0x74) & 8) != 0) {
      r_sch_slice_fg_remove(2);
    }
    puVar12 = (undefined1 *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
    *puVar12 = (char)param_2;
    puVar12[1] = (char)uVar9;
    puVar12[0x35] = 0;
    if ((uVar9 != 0) && (uVar9 = 0, *(short *)(iVar17 + 0x78) != 0)) {
      uVar9 = (uint)*(byte *)(iVar17 + 0x86);
    }
    puVar12[0x38] = (char)uVar9;
    r_ke_msg_send();
    r_ke_free(*(undefined4 *)(&lld_adv_env + param_2 * 4));
    *(undefined4 *)(&lld_adv_env + param_2 * 4) = 0;
  }
  return;
}

