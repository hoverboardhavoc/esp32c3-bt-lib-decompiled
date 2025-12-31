/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
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
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  byte bVar13;
  int iVar14;
  byte bVar15;
  int iVar16;
  undefined4 uStack_58;
  
  iVar14 = *(int *)(&lld_adv_env + param_1 * 4);
  bVar7 = false;
  if (iVar14 == 0) {
_L955:
    if ((adv_adv_data_need_to_set[param_1] != '\0') &&
       (((*(ushort *)(iVar14 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar14 + 0x74) & 0x14) == 0x10)))
       ) {
      r_lld_adv_adv_data_set_hack
                (param_1,*(undefined1 *)(iVar14 + 0x28),*(undefined2 *)(iVar14 + 0x24),1,1);
      *(undefined2 *)(iVar14 + 0x24) = 0;
      adv_adv_data_need_to_set[param_1] = 0;
    }
    if ((adv_scan_rsp_data_need_to_set[param_1] != '\0') &&
       (((*(ushort *)(iVar14 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar14 + 0x74) & 0x14) == 0x10)))
       ) {
      r_lld_adv_scan_rsp_data_set_hack
                (param_1,*(undefined1 *)(iVar14 + 0x2a),*(undefined2 *)(iVar14 + 0x26),1,1);
      *(undefined2 *)(iVar14 + 0x26) = 0;
      adv_scan_rsp_data_need_to_set[param_1] = 0;
    }
    r_lld_adv_frm_isr(param_1,param_2,param_3);
    if ((iVar14 != 0) && (bVar7)) {
      g_adv_delay_dis = '\0';
      *(undefined4 *)(iVar14 + 100) = uStack_58;
    }
    return;
  }
  bVar1 = *(uint *)(iVar14 + 100) < 0x20;
  bVar6 = g_adv_delay_dis == '\0';
  bVar7 = bVar1 && bVar6;
  bVar15 = *(byte *)(iVar14 + 0x87);
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  iVar9 = (uint)bVar15 * 0x5a;
  bVar15 = 1;
  uVar2 = *(ushort *)(iVar11 + iVar9 + 4);
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  uVar8 = (uVar2 & 0xc) << 2 | *(ushort *)(iVar11 + iVar9 + 4) & 3;
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  uVar3 = *(undefined2 *)(iVar9 + 0xe + iVar11);
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  uVar4 = *(undefined2 *)(iVar9 + 0xc + iVar11);
  uVar10 = *(uint *)(iVar14 + 4) * 0x271;
  uVar12 = *(int *)(iVar14 + 8) + uVar10;
  uVar10 = ((uint)(uVar12 < uVar10) + (int)((ulonglong)*(uint *)(iVar14 + 4) * 0x271 >> 0x20)) *
           -0x80000000 | uVar12 >> 1;
  if ((*(ushort *)(iVar14 + 0x74) & 0x10) == 0) {
    bVar15 = *(byte *)(iVar14 + 0x92);
  }
  bVar13 = 0;
  uVar12 = 0x25;
  do {
    do {
      if (((bVar15 <= bVar13) ||
          (r_ble_log_internal_x4
                     (0x40400000,CONCAT22(uVar3,uVar4),uVar10,*(undefined1 *)(iVar14 + 0x86),
                      (uint)*(byte *)(iVar14 + 0x87) | param_3 << 8 | uVar12 << 0x10 | uVar8 << 0x18
                     ), (*(ushort *)(iVar14 + 0x74) & 0x10) != 0)) || (bVar13 != 0)) {
        if ((param_3 == 0) && (g_ble_ext_config != '\0')) {
          DAT_00016594 = DAT_00016594 + 1;
        }
        if (bVar1 && bVar6) {
          g_adv_delay_dis = '\x01';
          uStack_58 = *(undefined4 *)(iVar14 + 100);
          uVar8 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
          uVar8 = uVar8 % 9;
          iVar9 = uVar8 << 1;
          if (*(char *)(iVar14 + 0x95) != '\0') {
            if (uVar8 == 0) {
              iVar9 = 1;
            }
            else if (uVar8 == 8) {
              iVar9 = 0xf;
            }
          }
          *(uint *)(iVar14 + 100) = (uint)(*(int *)(iVar14 + 100) * 2 + iVar9) >> 1;
        }
        goto _L955;
      }
      iVar11 = ((uint)*(byte *)(iVar14 + 0x87) * 9 & 0xff) * 0xe;
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      bVar13 = 1;
    } while ((*(ushort *)(iVar11 + 6 + iVar9) & 0x1000) == 0);
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar16 = iVar11 + 8;
    uVar12 = *(ushort *)(iVar9 + iVar16) & 0x3f;
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar8 = *(ushort *)(iVar9 + iVar11 + 10) >> 5 & 7;
    uVar8 = uVar8 | uVar8 << 4;
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar2 = *(ushort *)(iVar9 + iVar11 + 10);
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar5 = *(ushort *)(iVar9 + iVar16);
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar11 = 300;
    if ((*(ushort *)(iVar9 + iVar16) & 0x80) == 0) {
      iVar11 = 0x1e;
    }
    bVar13 = 1;
    uVar10 = uVar10 + (((uVar2 & 0x1f) << 8 | (uint)(uVar5 >> 8)) * iVar11 & 0xffff);
  } while( true );
}

