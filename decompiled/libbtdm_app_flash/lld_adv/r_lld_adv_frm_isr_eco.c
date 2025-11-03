/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_frm_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_isr_eco(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  byte bVar12;
  int iVar13;
  byte bVar14;
  int iVar15;
  uint uVar16;
  undefined4 uStack_58;
  
  iVar13 = *(int *)(&lld_adv_env + param_1 * 4);
  bVar7 = false;
  if (iVar13 == 0) {
_L955:
    if ((adv_adv_data_need_to_set[param_1] != '\0') &&
       (((*(ushort *)(iVar13 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar13 + 0x74) & 0x14) == 0x10)))
       ) {
      r_lld_adv_adv_data_set_hack
                (param_1,*(undefined1 *)(iVar13 + 0x28),*(undefined2 *)(iVar13 + 0x24),1,1);
      *(undefined2 *)(iVar13 + 0x24) = 0;
      adv_adv_data_need_to_set[param_1] = 0;
    }
    if ((adv_scan_rsp_data_need_to_set[param_1] != '\0') &&
       (((*(ushort *)(iVar13 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar13 + 0x74) & 0x14) == 0x10)))
       ) {
      r_lld_adv_scan_rsp_data_set_hack
                (param_1,*(undefined1 *)(iVar13 + 0x2a),*(undefined2 *)(iVar13 + 0x26),1,1);
      *(undefined2 *)(iVar13 + 0x26) = 0;
      adv_scan_rsp_data_need_to_set[param_1] = 0;
    }
    r_lld_adv_frm_isr(param_1,param_2,param_3);
    if ((iVar13 != 0) && (bVar7)) {
      g_adv_delay_dis = '\0';
      *(undefined4 *)(iVar13 + 100) = uStack_58;
    }
    return;
  }
  bVar1 = *(uint *)(iVar13 + 100) < 0x20;
  bVar6 = g_adv_delay_dis == '\0';
  bVar7 = bVar1 && bVar6;
  bVar14 = *(byte *)(iVar13 + 0x87);
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  iVar8 = (uint)bVar14 * 0x5a;
  bVar14 = 1;
  uVar2 = *(ushort *)(iVar10 + iVar8 + 4);
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  uVar16 = (uVar2 & 0xc) << 2 | *(ushort *)(iVar10 + iVar8 + 4) & 3;
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  uVar3 = *(undefined2 *)(iVar8 + 0xe + iVar10);
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  uVar4 = *(undefined2 *)(iVar8 + 0xc + iVar10);
  uVar9 = *(uint *)(iVar13 + 4) * 0x271;
  uVar11 = *(int *)(iVar13 + 8) + uVar9;
  uVar9 = ((uint)(uVar11 < uVar9) + (int)((ulonglong)*(uint *)(iVar13 + 4) * 0x271 >> 0x20)) *
          -0x80000000 | uVar11 >> 1;
  if ((*(ushort *)(iVar13 + 0x74) & 0x10) == 0) {
    bVar14 = *(byte *)(iVar13 + 0x92);
  }
  bVar12 = 0;
  uVar11 = 0x25;
  do {
    do {
      if (((bVar14 <= bVar12) ||
          (r_ble_log_internal_x3
                     (0x40400059,CONCAT22(uVar3,uVar4),uVar9,
                      (uint)*(byte *)(iVar13 + 0x87) | param_3 << 8 | uVar11 << 0x10 |
                      uVar16 << 0x18), (*(ushort *)(iVar13 + 0x74) & 0x10) != 0)) || (bVar12 != 0))
      {
        if ((param_3 == 0) && (g_ble_ext_config != '\0')) {
          DAT_000165a4 = DAT_000165a4 + 1;
        }
        if (bVar1 && bVar6) {
          g_adv_delay_dis = '\x01';
          uStack_58 = *(undefined4 *)(iVar13 + 100);
          uVar9 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
          uVar9 = uVar9 % 9;
          iVar8 = uVar9 << 1;
          if (*(char *)(iVar13 + 0x95) != '\0') {
            if (uVar9 == 0) {
              iVar8 = 1;
            }
            else if (uVar9 == 8) {
              iVar8 = 0xf;
            }
          }
          *(uint *)(iVar13 + 100) = (uint)(*(int *)(iVar13 + 100) * 2 + iVar8) >> 1;
        }
        goto _L955;
      }
      iVar10 = ((uint)*(byte *)(iVar13 + 0x87) * 9 & 0xff) * 0xe;
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      bVar12 = 1;
    } while ((*(ushort *)(iVar10 + 6 + iVar8) & 0x1000) == 0);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar15 = iVar10 + 8;
    uVar11 = *(ushort *)(iVar8 + iVar15) & 0x3f;
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar16 = *(ushort *)(iVar8 + iVar10 + 10) >> 5 & 7;
    uVar16 = uVar16 | uVar16 << 4;
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar2 = *(ushort *)(iVar8 + iVar10 + 10);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar5 = *(ushort *)(iVar8 + iVar15);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar10 = 300;
    if ((*(ushort *)(iVar8 + iVar15) & 0x80) == 0) {
      iVar10 = 0x1e;
    }
    bVar12 = 1;
    uVar9 = uVar9 + (((uVar2 & 0x1f) << 8 | (uint)(uVar5 >> 8)) * iVar10 & 0xffff);
  } while( true );
}

