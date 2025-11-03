/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  int iVar9;
  uint uVar10;
  undefined1 *puVar11;
  int iVar12;
  undefined4 uVar13;
  uint uVar14;
  byte bVar15;
  int iVar16;
  byte bVar17;
  int iVar18;
  uint uVar19;
  undefined4 uStack_58;
  
  if (param_3 == 2) {
    return;
  }
  if (param_3 < 3) {
    param_2 = param_2 & 0xff;
    if (param_3 != 0) {
      param_3 = 1;
    }
    iVar16 = *(int *)(&lld_adv_env + param_2 * 4);
    bVar7 = false;
    if (iVar16 == 0) {
_L955:
      if ((adv_adv_data_need_to_set[param_2] != '\0') &&
         (((*(ushort *)(iVar16 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar16 + 0x74) & 0x14) == 0x10)
          ))) {
        r_lld_adv_adv_data_set_hack
                  (param_2,*(undefined1 *)(iVar16 + 0x28),*(undefined2 *)(iVar16 + 0x24),1,1);
        *(undefined2 *)(iVar16 + 0x24) = 0;
        adv_adv_data_need_to_set[param_2] = 0;
      }
      if ((adv_scan_rsp_data_need_to_set[param_2] != '\0') &&
         (((*(ushort *)(iVar16 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar16 + 0x74) & 0x14) == 0x10)
          ))) {
        r_lld_adv_scan_rsp_data_set_hack
                  (param_2,*(undefined1 *)(iVar16 + 0x2a),*(undefined2 *)(iVar16 + 0x26),1,1);
        *(undefined2 *)(iVar16 + 0x26) = 0;
        adv_scan_rsp_data_need_to_set[param_2] = 0;
      }
      r_lld_adv_frm_isr(param_2,param_1,param_3);
      if ((iVar16 != 0) && (bVar7)) {
        g_adv_delay_dis = '\0';
        *(undefined4 *)(iVar16 + 100) = uStack_58;
      }
      return;
    }
    bVar1 = *(uint *)(iVar16 + 100) < 0x20;
    bVar6 = g_adv_delay_dis == '\0';
    bVar7 = bVar1 && bVar6;
    bVar17 = *(byte *)(iVar16 + 0x87);
    iVar12 = r_emi_get_mem_addr_by_offset(0x400);
    iVar9 = (uint)bVar17 * 0x5a;
    bVar17 = 1;
    uVar2 = *(ushort *)(iVar12 + iVar9 + 4);
    iVar12 = r_emi_get_mem_addr_by_offset(0x400);
    uVar19 = (uVar2 & 0xc) << 2 | *(ushort *)(iVar12 + iVar9 + 4) & 3;
    iVar12 = r_emi_get_mem_addr_by_offset(0x400);
    uVar3 = *(undefined2 *)(iVar9 + 0xe + iVar12);
    iVar12 = r_emi_get_mem_addr_by_offset(0x400);
    uVar4 = *(undefined2 *)(iVar9 + 0xc + iVar12);
    uVar10 = *(uint *)(iVar16 + 4) * 0x271;
    uVar14 = *(int *)(iVar16 + 8) + uVar10;
    uVar10 = ((uint)(uVar14 < uVar10) + (int)((ulonglong)*(uint *)(iVar16 + 4) * 0x271 >> 0x20)) *
             -0x80000000 | uVar14 >> 1;
    if ((*(ushort *)(iVar16 + 0x74) & 0x10) == 0) {
      bVar17 = *(byte *)(iVar16 + 0x92);
    }
    bVar15 = 0;
    uVar14 = 0x25;
    do {
      do {
        if (((bVar17 <= bVar15) ||
            (r_ble_log_internal_x3
                       (0x40400059,CONCAT22(uVar3,uVar4),uVar10,
                        (uint)*(byte *)(iVar16 + 0x87) | param_3 << 8 | uVar14 << 0x10 |
                        uVar19 << 0x18), (*(ushort *)(iVar16 + 0x74) & 0x10) != 0)) || (bVar15 != 0)
           ) {
          if ((param_3 == 0) && (g_ble_ext_config != '\0')) {
            DAT_000165a4 = DAT_000165a4 + 1;
          }
          if (bVar1 && bVar6) {
            g_adv_delay_dis = '\x01';
            uStack_58 = *(undefined4 *)(iVar16 + 100);
            uVar10 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
            uVar10 = uVar10 % 9;
            iVar9 = uVar10 << 1;
            if (*(char *)(iVar16 + 0x95) != '\0') {
              if (uVar10 == 0) {
                iVar9 = 1;
              }
              else if (uVar10 == 8) {
                iVar9 = 0xf;
              }
            }
            *(uint *)(iVar16 + 100) = (uint)(*(int *)(iVar16 + 100) * 2 + iVar9) >> 1;
          }
          goto _L955;
        }
        iVar12 = ((uint)*(byte *)(iVar16 + 0x87) * 9 & 0xff) * 0xe;
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        bVar15 = 1;
      } while ((*(ushort *)(iVar12 + 6 + iVar9) & 0x1000) == 0);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar18 = iVar12 + 8;
      uVar14 = *(ushort *)(iVar9 + iVar18) & 0x3f;
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar19 = *(ushort *)(iVar9 + iVar12 + 10) >> 5 & 7;
      uVar19 = uVar19 | uVar19 << 4;
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar2 = *(ushort *)(iVar9 + iVar12 + 10);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar5 = *(ushort *)(iVar9 + iVar18);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar12 = 300;
      if ((*(ushort *)(iVar9 + iVar18) & 0x80) == 0) {
        iVar12 = 0x1e;
      }
      bVar15 = 1;
      uVar10 = uVar10 + (((uVar2 & 0x1f) << 8 | (uint)(uVar5 >> 8)) * iVar12 & 0xffff);
    } while( true );
  }
  if (param_3 != 4) {
    r_assert_param(param_3,0x10000,0xbaf);
    return;
  }
  param_2 = param_2 & 0xff;
  iVar16 = *(int *)(&lld_adv_env + param_2 * 4);
  if (iVar16 == 0) {
    uVar13 = 0xb8e;
_L1024:
    r_assert_err(0,0x10000,uVar13);
    return;
  }
  r_ble_log_internal_x2(0x4040006d,(uint)*(byte *)(iVar16 + 0x89) << 8 | param_2);
  if (1 < (byte)(*(char *)(iVar16 + 0x89) - 1U)) {
    r_assert_err(0,0x10000,0xb43);
  }
  if (*(char *)(iVar16 + 0x89) == '\x02') {
    uVar10 = 0;
  }
  else {
    if ((*(char *)(iVar16 + 0x95) == '\0') || (*(int *)(iVar16 + 0x38) != param_1)) {
      r_sch_arb_remove(iVar16,1);
      if ((*(ushort *)(iVar16 + 0x74) & 8) == 0) {
        if ((uint)(*(int *)(iVar16 + 100) << 1) <= (param_1 - *(int *)(iVar16 + 0x5c) & 0xfffffffU))
        {
          *(char *)(iVar16 + 0x16) = *(char *)(iVar16 + 0x16) + rwip_priority;
          *(undefined4 *)(iVar16 + 0x5c) = *(undefined4 *)(iVar16 + 4);
        }
      }
      else {
        *(char *)(iVar16 + 0x16) = *(char *)(iVar16 + 0x16) + rwip_priority;
      }
      iVar9 = r_sch_arb_insert(iVar16);
      if (iVar9 == 0) goto _L1017;
      if (*(char *)(iVar16 + 0x95) != '\0') {
        return;
      }
      if (*(int *)(iVar16 + 0x58) == -1) {
        uVar13 = 0xb82;
        goto _L1024;
      }
    }
    else {
      r_sch_arb_remove(iVar16 + 0x34,1);
      cVar8 = rwip_priority;
      if ((uint)(*(int *)(iVar16 + 100) << 1) <= (param_1 - *(int *)(iVar16 + 0x60) & 0xfffffffU)) {
        *(int *)(iVar16 + 0x60) = param_1;
        *(char *)(iVar16 + 0x4a) = *(char *)(iVar16 + 0x4a) + cVar8;
      }
      iVar9 = r_sch_arb_insert(iVar16 + 0x34);
      if (iVar9 == 0) {
_L1017:
        *(undefined1 *)(iVar16 + 0x89) = 0;
        return;
      }
      if (*(int *)(iVar16 + 0x58) == -1) {
        uVar13 = 0xb60;
        goto _L1024;
      }
    }
    param_2 = (uint)*(byte *)(iVar16 + 0x87);
    uVar10 = 0x3c;
  }
  iVar16 = *(int *)(&lld_adv_env + param_2 * 4);
  if (iVar16 != 0) {
    r_ble_log_internal_x1
              (0x4000005d,(uint)*(byte *)(iVar16 + 0x89) << 0x18 | uVar10 << 0x10 | 0x100 | param_2)
    ;
    if ((((*(short *)(iVar16 + 0x24) != 0) && (*(short *)(iVar16 + 0x7e) != 0)) &&
        (*(short *)(iVar16 + 0x24) != *(short *)(iVar16 + 0x7e))) &&
       (((*(ushort *)(iVar16 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar16 + 0x74) & 0x14) == 0x10)))
       ) {
      iVar9 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar9 == 0) {
        r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar16 + 0x7e));
      }
      else {
        r_ble_util_buf_adv_tx_free_in_isr();
      }
    }
    if (((*(short *)(iVar16 + 0x26) != 0) && (*(short *)(iVar16 + 0x80) != 0)) &&
       ((*(short *)(iVar16 + 0x26) != *(short *)(iVar16 + 0x80) &&
        (((*(ushort *)(iVar16 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar16 + 0x74) & 0x14) == 0x10))
        )))) {
      iVar9 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar9 == 0) {
        r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar16 + 0x80));
      }
      else {
        r_ble_util_buf_adv_tx_free_in_isr();
      }
    }
  }
  iVar16 = *(int *)(&lld_adv_env + param_2 * 4);
  if (iVar16 != 0) {
    r_sch_arb_remove(iVar16,0);
    if (*(char *)(iVar16 + 0x95) != '\0') {
      r_sch_arb_remove(iVar16 + 0x34,0);
    }
    if ((*(ushort *)(iVar16 + 0x74) & 8) != 0) {
      r_sch_slice_fg_remove(2);
    }
    puVar11 = (undefined1 *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
    *puVar11 = (char)param_2;
    puVar11[1] = (char)uVar10;
    puVar11[0x35] = 0;
    if ((uVar10 != 0) && (uVar10 = 0, *(short *)(iVar16 + 0x78) != 0)) {
      uVar10 = (uint)*(byte *)(iVar16 + 0x86);
    }
    puVar11[0x38] = (char)uVar10;
    r_ke_msg_send();
    r_ke_free(*(undefined4 *)(&lld_adv_env + param_2 * 4));
    *(undefined4 *)(&lld_adv_env + param_2 * 4) = 0;
  }
  return;
}

