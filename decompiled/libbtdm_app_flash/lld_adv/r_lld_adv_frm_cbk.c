/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_cbk(int param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  bool bVar5;
  char cVar6;
  uint uVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  byte bVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  byte bVar16;
  int iVar17;
  undefined4 uStack_58;
  
  if (param_3 == 2) {
    return;
  }
  if (param_3 < 3) {
    param_2 = param_2 & 0xff;
    if (param_3 != 0) {
      param_3 = 1;
    }
    iVar15 = *(int *)(&lld_adv_env + param_2 * 4);
    bVar5 = false;
    if (iVar15 == 0) {
_L983:
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      r_ble_log_internal_x1(0x404000d6,param_2 << 0x10 | *(ushort *)(param_2 * 0x5a + iVar9) & 0x1f)
      ;
      if (((iVar15 != 0) && (param_3 == 0)) && (g_ble_ext_config != '\0')) {
        DAT_00016944 = DAT_00016944 + 1;
      }
      if (bVar5) {
        g_adv_delay_dis = '\x01';
        uStack_58 = *(undefined4 *)(iVar15 + 100);
        uVar7 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
        uVar7 = uVar7 % 9;
        iVar9 = uVar7 << 1;
        if (*(char *)(iVar15 + 0x95) != '\0') {
          if (uVar7 == 0) {
            iVar9 = 1;
          }
          else if (uVar7 == 8) {
            iVar9 = 0xf;
          }
        }
        *(uint *)(iVar15 + 100) = (uint)(*(int *)(iVar15 + 100) * 2 + iVar9) >> 1;
      }
      if ((adv_adv_data_need_to_set[param_2] != '\0') &&
         (((*(ushort *)(iVar15 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar15 + 0x74) & 0x14) == 0x10)
          ))) {
        r_lld_adv_adv_data_set_hack
                  (param_2,*(undefined1 *)(iVar15 + 0x28),*(undefined2 *)(iVar15 + 0x24),1,1);
        *(undefined2 *)(iVar15 + 0x24) = 0;
        adv_adv_data_need_to_set[param_2] = 0;
      }
      if ((adv_scan_rsp_data_need_to_set[param_2] != '\0') &&
         (((*(ushort *)(iVar15 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar15 + 0x74) & 0x14) == 0x10)
          ))) {
        r_lld_adv_scan_rsp_data_set_hack
                  (param_2,*(undefined1 *)(iVar15 + 0x2a),*(undefined2 *)(iVar15 + 0x26),1,1);
        *(undefined2 *)(iVar15 + 0x26) = 0;
        adv_scan_rsp_data_need_to_set[param_2] = 0;
      }
      r_lld_adv_frm_isr(param_2,param_1,param_3);
      if ((iVar15 != 0) && (bVar5)) {
        g_adv_delay_dis = '\0';
        *(undefined4 *)(iVar15 + 100) = uStack_58;
      }
      return;
    }
    bVar5 = *(uint *)(iVar15 + 100) < 0x20 && g_adv_delay_dis == '\0';
    bVar16 = *(byte *)(iVar15 + 0x87);
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    iVar13 = (uint)bVar16 * 0x5a;
    bVar16 = 1;
    uVar1 = *(ushort *)(iVar9 + iVar13 + 4);
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    uVar7 = (uVar1 & 0xc) << 2 | *(ushort *)(iVar9 + iVar13 + 4) & 3;
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(undefined2 *)(iVar13 + 0xe + iVar9);
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    uVar3 = *(undefined2 *)(iVar13 + 0xc + iVar9);
    uVar14 = *(uint *)(iVar15 + 4) * 0x271;
    uVar11 = *(int *)(iVar15 + 8) + uVar14;
    uVar11 = ((uint)(uVar11 < uVar14) + (int)((ulonglong)*(uint *)(iVar15 + 4) * 0x271 >> 0x20)) *
             -0x80000000 | uVar11 >> 1;
    if ((*(ushort *)(iVar15 + 0x74) & 0x10) == 0) {
      bVar16 = *(byte *)(iVar15 + 0x92);
    }
    bVar12 = 0;
    uVar14 = 0x25;
    do {
      do {
        if (((bVar16 <= bVar12) ||
            (r_ble_log_internal_x4
                       (0x40400000,CONCAT22(uVar2,uVar3),uVar11,*(undefined1 *)(iVar15 + 0x86),
                        (uint)*(byte *)(iVar15 + 0x87) | param_3 << 8 | uVar14 << 0x10 |
                        uVar7 << 0x18), (*(ushort *)(iVar15 + 0x74) & 0x10) != 0)) || (bVar12 != 0))
        goto _L983;
        iVar13 = ((uint)*(byte *)(iVar15 + 0x87) * 9 & 0xff) * 0xe;
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        bVar12 = 1;
      } while ((*(ushort *)(iVar13 + 6 + iVar9) & 0x1000) == 0);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar17 = iVar13 + 8;
      uVar14 = *(ushort *)(iVar9 + iVar17) & 0x3f;
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar7 = *(ushort *)(iVar9 + iVar13 + 10) >> 5 & 7;
      uVar7 = uVar7 | uVar7 << 4;
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar1 = *(ushort *)(iVar13 + 10 + iVar9);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar4 = *(ushort *)(iVar9 + iVar17);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar13 = 300;
      if ((*(ushort *)(iVar17 + iVar9) & 0x80) == 0) {
        iVar13 = 0x1e;
      }
      bVar12 = 1;
      uVar11 = uVar11 + (((uVar1 & 0x1f) << 8 | (uint)(uVar4 >> 8)) * iVar13 & 0xffff);
    } while( true );
  }
  if (param_3 != 4) {
    r_assert_param(param_3,0x10000,0xc07);
    return;
  }
  param_2 = param_2 & 0xff;
  iVar15 = *(int *)(&lld_adv_env + param_2 * 4);
  if (iVar15 == 0) {
    uVar10 = 0xbe6;
_L1053:
    r_assert_err(0,0x10000,uVar10);
    return;
  }
  r_ble_log_internal_x2(0x404000ed,(uint)*(byte *)(iVar15 + 0x89) << 8 | param_2);
  if (1 < (byte)(*(char *)(iVar15 + 0x89) - 1U)) {
    r_assert_err(0,0x10000,0xb9b);
  }
  if (*(char *)(iVar15 + 0x89) == '\x02') {
    uVar7 = 0;
  }
  else {
    if ((*(char *)(iVar15 + 0x95) == '\0') || (*(int *)(iVar15 + 0x38) != param_1)) {
      r_sch_arb_remove(iVar15,1);
      if ((*(ushort *)(iVar15 + 0x74) & 8) == 0) {
        if ((uint)(*(int *)(iVar15 + 100) << 1) <= (param_1 - *(int *)(iVar15 + 0x5c) & 0xfffffffU))
        {
          *(char *)(iVar15 + 0x16) = *(char *)(iVar15 + 0x16) + rwip_priority;
          *(undefined4 *)(iVar15 + 0x5c) = *(undefined4 *)(iVar15 + 4);
        }
      }
      else {
        *(char *)(iVar15 + 0x16) = *(char *)(iVar15 + 0x16) + rwip_priority;
      }
      iVar9 = r_sch_arb_insert(iVar15);
      if (iVar9 == 0) goto _L1046;
      if (*(char *)(iVar15 + 0x95) != '\0') {
        return;
      }
      if (*(int *)(iVar15 + 0x58) == -1) {
        uVar10 = 0xbda;
        goto _L1053;
      }
    }
    else {
      r_sch_arb_remove(iVar15 + 0x34,1);
      cVar6 = rwip_priority;
      if ((uint)(*(int *)(iVar15 + 100) << 1) <= (param_1 - *(int *)(iVar15 + 0x60) & 0xfffffffU)) {
        *(int *)(iVar15 + 0x60) = param_1;
        *(char *)(iVar15 + 0x4a) = *(char *)(iVar15 + 0x4a) + cVar6;
      }
      iVar9 = r_sch_arb_insert(iVar15 + 0x34);
      if (iVar9 == 0) {
_L1046:
        *(undefined1 *)(iVar15 + 0x89) = 0;
        return;
      }
      if (*(int *)(iVar15 + 0x58) == -1) {
        uVar10 = 3000;
        goto _L1053;
      }
    }
    param_2 = (uint)*(byte *)(iVar15 + 0x87);
    uVar7 = 0x3c;
  }
  iVar15 = *(int *)(&lld_adv_env + param_2 * 4);
  if (iVar15 != 0) {
    r_ble_log_internal_x1
              (0x400000da,(uint)*(byte *)(iVar15 + 0x89) << 0x18 | uVar7 << 0x10 | 0x100 | param_2);
    if ((((*(short *)(iVar15 + 0x24) != 0) && (*(short *)(iVar15 + 0x7e) != 0)) &&
        (*(short *)(iVar15 + 0x24) != *(short *)(iVar15 + 0x7e))) &&
       (((*(ushort *)(iVar15 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar15 + 0x74) & 0x14) == 0x10)))
       ) {
      iVar9 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar9 == 0) {
        r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar15 + 0x7e));
      }
      else {
        r_ble_util_buf_adv_tx_free_in_isr();
      }
    }
    if (((*(short *)(iVar15 + 0x26) != 0) && (*(short *)(iVar15 + 0x80) != 0)) &&
       ((*(short *)(iVar15 + 0x26) != *(short *)(iVar15 + 0x80) &&
        (((*(ushort *)(iVar15 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar15 + 0x74) & 0x14) == 0x10))
        )))) {
      iVar9 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar9 == 0) {
        r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar15 + 0x80));
      }
      else {
        r_ble_util_buf_adv_tx_free_in_isr();
      }
    }
  }
  iVar15 = *(int *)(&lld_adv_env + param_2 * 4);
  if (iVar15 != 0) {
    r_sch_arb_remove(iVar15,0);
    if (*(char *)(iVar15 + 0x95) != '\0') {
      r_sch_arb_remove(iVar15 + 0x34,0);
    }
    if ((*(ushort *)(iVar15 + 0x74) & 8) != 0) {
      r_sch_slice_fg_remove(2);
    }
    puVar8 = (undefined1 *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
    *puVar8 = (char)param_2;
    puVar8[1] = (char)uVar7;
    puVar8[0x35] = 0;
    if ((uVar7 != 0) && (uVar7 = 0, *(short *)(iVar15 + 0x78) != 0)) {
      uVar7 = (uint)*(byte *)(iVar15 + 0x86);
    }
    puVar8[0x38] = (char)uVar7;
    r_ke_msg_send();
    r_ke_free(*(undefined4 *)(&lld_adv_env + param_2 * 4));
    *(undefined4 *)(&lld_adv_env + param_2 * 4) = 0;
  }
  return;
}

