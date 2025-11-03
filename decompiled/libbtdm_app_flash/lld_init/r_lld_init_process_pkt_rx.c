/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_process_pkt_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_process_pkt_rx(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  ushort uVar16;
  int iVar17;
  
  iVar7 = _lld_init_env;
  if ((_lld_init_env != 0) && (iVar8 = *(int *)(param_1 * 4 + _lld_init_env), iVar8 != 0)) {
    while (iVar9 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar8 + 0x52)), iVar9 != 0) {
      bVar1 = *(byte *)(_p_lld_env + 0xd8);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar9 = (uint)bVar1 * 0x14;
      bVar2 = *(byte *)(iVar8 + 0x52);
      uVar16 = *(ushort *)(iVar9 + 2 + iVar10);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      iVar17 = iVar9 + 4;
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000,*(undefined2 *)((uint)bVar2 * 0x5a + iVar10));
      uVar3 = *(ushort *)(iVar10 + iVar9 + 6);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar4 = *(ushort *)(iVar10 + iVar17);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar12 = (uint)(*(ushort *)(iVar10 + iVar9 + 6) >> 0xe);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar5 = *(undefined2 *)(iVar9 + 10 + iVar10);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar6 = *(undefined2 *)(iVar9 + 8 + iVar10);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar13 = CONCAT22(uVar5,uVar6);
      uVar11 = uVar13 * 0x271;
      uVar14 = (0x270 - (*(ushort *)(iVar9 + 0xc + iVar10) & 0x3ff) & 0xffff) + uVar11;
      uVar15 = init_rx_aux_data;
      if ((*(char *)(iVar8 + 0x3d) == '\0') && ((uVar4 & 0xf) != 8)) {
        uVar15 = (int)(uint)uVar3 >> 8;
      }
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      r_ble_log_internal_x3
                (0x2082009c,
                 ((uint)(uVar14 < uVar11) + (int)((ulonglong)uVar13 * 0x271 >> 0x20)) * -0x80000000
                 | uVar14 >> 1,CONCAT22(*(undefined2 *)(iVar10 + iVar17),uVar16),
                 (uint)CONCAT11(bVar1,*(undefined1 *)(iVar8 + 0x52)) |
                 (uVar12 << 4 | uVar12) << 0x18 | (uVar15 & 0x3f) << 0x10);
      if (((uVar16 & 0x603d) == 0) && (*(char *)(iVar7 + 0x50) == '\0')) {
        iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar16 = *(ushort *)(iVar10 + iVar17);
        iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar5 = *(undefined2 *)(iVar9 + 0x12 + iVar10);
        *(undefined1 *)(iVar8 + 0x50) = 1;
        if ((uVar16 & 0xe) == 0) {
          r_lld_init_process_pkt_rx_adv_ind_or_direct_ind(param_1);
        }
        else {
          iVar10 = r_sdk_config_get_opts_ext();
          if (*(char *)(iVar10 + 0x18) != '\0') {
            iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
            uVar16 = uVar16 & 0xf;
            if (uVar16 == 7) {
              if ((*(ushort *)(iVar9 + 0x10 + iVar10) & 0x40) != 0) {
                r_lld_init_process_pkt_rx_adv_ext_ind(param_1);
              }
            }
            else if (uVar16 == 8) {
              r_lld_init_process_pkt_rx_aux_connect_rsp(param_1,uVar5);
            }
          }
        }
      }
      r_lld_rxdesc_free();
    }
    if ((*(char *)(iVar8 + 0x3d) == '\x02') ||
       ((*(char *)(iVar8 + 0x50) == '\0' && (*(char *)(iVar8 + 0x3d) == '\x01')))) {
      *(undefined1 *)(iVar8 + 0x3d) = 0;
    }
    return;
  }
  r_assert_err(0,0x10000,0x3cb);
  return;
}

