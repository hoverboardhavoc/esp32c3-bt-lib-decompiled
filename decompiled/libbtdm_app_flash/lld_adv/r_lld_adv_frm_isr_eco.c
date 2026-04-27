/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_frm_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_isr_eco(int param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  byte bVar13;
  int iVar14;
  undefined4 uStack_58;
  
  iVar12 = *(int *)(&lld_adv_env + param_1 * 4);
  bVar5 = false;
  if (iVar12 != 0) {
    bVar5 = *(uint *)(iVar12 + 100) < 0x20 && g_adv_delay_dis == '\0';
    bVar13 = *(byte *)(iVar12 + 0x87);
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    iVar10 = (uint)bVar13 * 0x5a;
    bVar13 = 1;
    uVar1 = *(ushort *)(iVar7 + iVar10 + 4);
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    uVar6 = (uVar1 & 0xc) << 2 | *(ushort *)(iVar7 + iVar10 + 4) & 3;
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(undefined2 *)(iVar10 + 0xe + iVar7);
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    uVar3 = *(undefined2 *)(iVar10 + 0xc + iVar7);
    uVar11 = *(uint *)(iVar12 + 4) * 0x271;
    uVar8 = *(int *)(iVar12 + 8) + uVar11;
    uVar8 = ((uint)(uVar8 < uVar11) + (int)((ulonglong)*(uint *)(iVar12 + 4) * 0x271 >> 0x20)) *
            -0x80000000 | uVar8 >> 1;
    if ((*(ushort *)(iVar12 + 0x74) & 0x10) == 0) {
      bVar13 = *(byte *)(iVar12 + 0x92);
    }
    bVar9 = 0;
    uVar11 = 0x25;
    do {
      do {
        if (((bVar13 <= bVar9) ||
            (r_ble_log_internal_x4
                       (0x40400000,CONCAT22(uVar2,uVar3),uVar8,*(undefined1 *)(iVar12 + 0x86),
                        (uint)*(byte *)(iVar12 + 0x87) | param_3 << 8 | uVar11 << 0x10 |
                        uVar6 << 0x18), (*(ushort *)(iVar12 + 0x74) & 0x10) != 0)) || (bVar9 != 0))
        goto _L983;
        iVar10 = ((uint)*(byte *)(iVar12 + 0x87) * 9 & 0xff) * 0xe;
        iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
        bVar9 = 1;
      } while ((*(ushort *)(iVar10 + 6 + iVar7) & 0x1000) == 0);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar14 = iVar10 + 8;
      uVar11 = *(ushort *)(iVar7 + iVar14) & 0x3f;
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar6 = *(ushort *)(iVar7 + iVar10 + 10) >> 5 & 7;
      uVar6 = uVar6 | uVar6 << 4;
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar1 = *(ushort *)(iVar10 + 10 + iVar7);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar4 = *(ushort *)(iVar7 + iVar14);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar10 = 300;
      if ((*(ushort *)(iVar14 + iVar7) & 0x80) == 0) {
        iVar10 = 0x1e;
      }
      bVar9 = 1;
      uVar8 = uVar8 + (((uVar1 & 0x1f) << 8 | (uint)(uVar4 >> 8)) * iVar10 & 0xffff);
    } while( true );
  }
_L983:
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  r_ble_log_internal_x1(0x404000d6,param_1 << 0x10 | *(ushort *)(param_1 * 0x5a + iVar7) & 0x1f);
  if (((iVar12 != 0) && (param_3 == 0)) && (g_ble_ext_config != '\0')) {
    DAT_00016944 = DAT_00016944 + 1;
  }
  if (bVar5) {
    g_adv_delay_dis = '\x01';
    uStack_58 = *(undefined4 *)(iVar12 + 100);
    uVar6 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    uVar6 = uVar6 % 9;
    iVar7 = uVar6 << 1;
    if (*(char *)(iVar12 + 0x95) != '\0') {
      if (uVar6 == 0) {
        iVar7 = 1;
      }
      else if (uVar6 == 8) {
        iVar7 = 0xf;
      }
    }
    *(uint *)(iVar12 + 100) = (uint)(*(int *)(iVar12 + 100) * 2 + iVar7) >> 1;
  }
  if ((adv_adv_data_need_to_set[param_1] != '\0') &&
     (((*(ushort *)(iVar12 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar12 + 0x74) & 0x14) == 0x10))))
  {
    r_lld_adv_adv_data_set_hack
              (param_1,*(undefined1 *)(iVar12 + 0x28),*(undefined2 *)(iVar12 + 0x24),1,1);
    *(undefined2 *)(iVar12 + 0x24) = 0;
    adv_adv_data_need_to_set[param_1] = 0;
  }
  if ((adv_scan_rsp_data_need_to_set[param_1] != '\0') &&
     (((*(ushort *)(iVar12 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar12 + 0x74) & 0x14) == 0x10))))
  {
    r_lld_adv_scan_rsp_data_set_hack
              (param_1,*(undefined1 *)(iVar12 + 0x2a),*(undefined2 *)(iVar12 + 0x26),1,1);
    *(undefined2 *)(iVar12 + 0x26) = 0;
    adv_scan_rsp_data_need_to_set[param_1] = 0;
  }
  r_lld_adv_frm_isr(param_1,param_2,param_3);
  if ((iVar12 != 0) && (bVar5)) {
    g_adv_delay_dis = '\0';
    *(undefined4 *)(iVar12 + 100) = uStack_58;
  }
  return;
}

