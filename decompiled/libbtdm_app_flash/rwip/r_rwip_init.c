/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> rwip.o -> r_rwip_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_init(void)

{
  int iVar1;
  undefined4 uVar2;
  
  _rwip_param = &r_nvds_get;
  _r_nvds_put = &r_nvds_put;
  _r_nvds_del = &r_nvds_del;
  _LANCHOR0 = 0;
  r_ke_init();
  r_ke_mem_init(0,*_btdm_env_p,*(undefined2 *)(_btdm_env_p + 1));
  if (sdk_cfg_priv_opts != '\0') {
    r_ke_mem_init(1,_btdm_env_p[6],*(undefined2 *)(_btdm_env_p + 7));
  }
  r_ke_mem_init(2,_btdm_env_p[2],*(undefined2 *)(_btdm_env_p + 3));
  r_ke_mem_init(3,_btdm_env_p[4],*(undefined2 *)(_btdm_env_p + 5));
  r_vshci_init(_LANCHOR0);
  r_bt_rma_init();
  r_bt_rtp_init();
  rtp_pwr_tbl_desc_init();
  r_rw_rf_init(&rwip_rf);
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x20) != '\0') {
    r_ecc_init(_LANCHOR0);
  }
  iVar1 = r_sdk_config_get_opts();
  if (*(char *)(iVar1 + 0x17) == '\0') {
    uVar2 = r_rwip_eif_get(0);
    r_h4tl_init(0,uVar2);
  }
  else {
    iVar1 = r_sdk_config_get_opts();
    if (*(char *)(iVar1 + 0x17) == '\x01') {
      r_vhci_flow_on();
    }
  }
  r_misc_init(_LANCHOR0);
  r_hci_init(_LANCHOR0);
  if (*(code **)(_r_hli_funcs_p + 0xc) != (code *)0x0) {
    (**(code **)(_r_hli_funcs_p + 0xc))();
  }
  if (*(code **)(_r_hli_funcs_p + 8) != (code *)0x0) {
    (**(code **)(_r_hli_funcs_p + 8))(_LANCHOR0);
  }
  r_rwble_init(_LANCHOR0);
  bb_int_init(_LANCHOR0);
  r_rwip_driver_init(_LANCHOR0);
  r_rwip_wlcoex_set_part_0();
  _LANCHOR0 = 1;
  _btdm_pwr_state = 0;
                    /* WARNING: Could not recover jumptable at 0x000101e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x38))(g_waking_sleeping_sem);
  return;
}

