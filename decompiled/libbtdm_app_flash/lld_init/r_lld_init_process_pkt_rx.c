/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  
  iVar3 = _lld_init_env;
  if ((_lld_init_env != 0) && (iVar4 = *(int *)(param_1 * 4 + _lld_init_env), iVar4 != 0)) {
    while (iVar5 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar4 + 0x52)), iVar5 != 0) {
      bVar1 = *(byte *)(_p_lld_env + 0xd8);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar5 = (uint)bVar1 * 0x14;
      if (((*(ushort *)(iVar6 + iVar5 + 2) & 0x603d) == 0) && (*(char *)(iVar3 + 0x50) == '\0')) {
        iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar7 = *(ushort *)(iVar6 + iVar5 + 4);
        iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar2 = *(undefined2 *)(iVar6 + iVar5 + 0x12);
        *(undefined1 *)(iVar4 + 0x50) = 1;
        if ((uVar7 & 0xe) == 0) {
          r_lld_init_process_pkt_rx_adv_ind_or_direct_ind(param_1);
        }
        else {
          iVar6 = r_sdk_config_get_opts_ext();
          if (*(char *)(iVar6 + 0x18) != '\0') {
            iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
            uVar7 = uVar7 & 0xf;
            if (uVar7 == 7) {
              if ((*(ushort *)(iVar5 + 0x10 + iVar6) & 0x40) != 0) {
                r_lld_init_process_pkt_rx_adv_ext_ind(param_1);
              }
            }
            else if (uVar7 == 8) {
              r_lld_init_process_pkt_rx_aux_connect_rsp(param_1,uVar2);
            }
          }
        }
      }
      r_lld_rxdesc_free();
    }
    if ((*(char *)(iVar4 + 0x3d) == '\x02') ||
       ((*(char *)(iVar4 + 0x50) == '\0' && (*(char *)(iVar4 + 0x3d) == '\x01')))) {
      *(undefined1 *)(iVar4 + 0x3d) = 0;
    }
    return;
  }
  r_assert_err(0,"lld_init.c",0x39a);
  return;
}

