/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = _lld_init_env;
  if ((_lld_init_env != 0) && (iVar5 = *(int *)(param_1 * 4 + _lld_init_env), iVar5 != 0)) {
    while (iVar7 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar5 + 0x52)), iVar7 != 0) {
      bVar1 = *(byte *)(_p_lld_env + 0xd8);
      uVar6 = (uint)bVar1;
      iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar8 = uVar6 * 0x14;
      if (((*(ushort *)(iVar8 + 2 + iVar7) & 0x603d) == 0) && (*(char *)(iVar4 + 0x50) == '\0')) {
        iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar2 = *(ushort *)(iVar8 + 4 + iVar7);
        iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar3 = *(undefined2 *)(iVar8 + 0x12 + iVar7);
        iVar7 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar7 + 0x28) & 0x10) != 0) &&
           (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
          r_ble_log_internal_x1
                    (0x408f000a,
                     CONCAT22(uVar2,CONCAT11(bVar1,*(undefined1 *)(iVar5 + 0x52))) & 0xfffff);
        }
        *(undefined1 *)(iVar5 + 0x50) = 1;
        if ((uVar2 & 0xe) == 0) {
          r_lld_init_process_pkt_rx_adv_ind_or_direct_ind(param_1,uVar3);
        }
        else {
          iVar7 = r_sdk_config_get_opts_ext();
          if (*(char *)(iVar7 + 0x18) != '\0') {
            iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
            if ((uVar2 & 0xf) == 7) {
              if ((*(ushort *)(iVar8 + 0x10 + iVar7) & 0x40) != 0) {
                r_lld_init_process_pkt_rx_adv_ext_ind(param_1,uVar3);
              }
            }
            else if ((uVar2 & 0xf) == 8) {
              r_lld_init_process_pkt_rx_aux_connect_rsp(param_1,uVar3);
            }
          }
        }
      }
      else {
        iVar7 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar7 + 0x28) & 0x10) != 0) &&
           (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
          r_ble_log_internal_x2
                    (0x408f000b,
                     (uint)*(byte *)(iVar5 + 0x52) |
                     (uint)*(byte *)(iVar4 + 0x50) << 0x10 | uVar6 << 8,uVar6);
        }
      }
      r_lld_rxdesc_free();
    }
    if ((*(char *)(iVar5 + 0x3d) == '\x02') ||
       ((*(char *)(iVar5 + 0x50) == '\0' && (*(char *)(iVar5 + 0x3d) == '\x01')))) {
      *(undefined1 *)(iVar5 + 0x3d) = 0;
    }
    return;
  }
  r_assert_err(0,0x10000,0x3a4);
  return;
}

