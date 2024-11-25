/*
 * Last changed at upstream commit d23ae97bb91d66e08c58bfaabaeed0a5ba7b7b5d
 * https://github.com/espressif/esp32c3-bt-lib/commit/d23ae97bb91d66e08c58bfaabaeed0a5ba7b7b5d
 * Upstream date: 2024-11-25 10:28:56 +0800
 * Upstream subject: fix(bt): Fixed BLE assert ke_mem.c line 267(d7561c2)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_controller_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_controller_task(void)

{
  bool bVar1;
  int iVar2;
  code *pcVar3;
  char cStack_38;
  undefined1 uStack_37;
  undefined1 *puStack_34;
  
  _LANCHOR5 = 0;
  do {
    pcVar3 = *(code **)(_r_osi_funcs_p + 0x34);
    iVar2 = r_btdm_vnd_ol_task_env_get();
    iVar2 = (*pcVar3)(*(undefined4 *)(iVar2 + 8),0xffffffff);
    if (iVar2 == 0) {
      return;
    }
    bVar1 = false;
    while (iVar2 = (**(code **)(_r_osi_funcs_p + 0x5c))
                             (_g_rw_schd_queue,&cStack_38,0,*(code **)(_r_osi_funcs_p + 0x5c)),
          iVar2 == 1) {
      switch(cStack_38) {
      case '\x02':
        r_hci_tl_hci_pkt_handler();
        break;
      case '\a':
      case '\b':
      case '\t':
      case '\n':
        if (cStack_38 == '\t') {
          r_sdk_config_get_opts();
          bt_bb_v2_init_cmplx(0);
          r_cali_phase_match_p();
          r_rf_rw_v9_le_init();
          btdm_controller_on_reset();
          r_intc_enable();
          iVar2 = (**(code **)(_r_osi_funcs_p + 0xb4))
                            (&coex_schm_btdm_callback,*(code **)(_r_osi_funcs_p + 0xb4));
          if (iVar2 == 0) {
            btdm_vnd_offload_task_register(1,&coex_schm_process);
          }
          else if (1 < _g_bt_plf_log_level) {
            ets_printf("Coex register schm btdm cb faild\n");
          }
          _LANCHOR5 = 2;
        }
        else {
          if (cStack_38 == '\n') {
            (**(code **)(_r_osi_funcs_p + 0xb4))(0,*(code **)(_r_osi_funcs_p + 0xb4));
            r_sdk_config_get_opts();
            r_intc_disable();
            btdm_controller_on_reset();
            r_rwble_hw_disable(2);
          }
          else {
            if (cStack_38 == '\b') {
              rw_stop();
              _LANCHOR5 = 0;
              goto _L408;
            }
            rw_pre_main();
          }
          _LANCHOR5 = 1;
        }
_L408:
        (**(code **)(_r_osi_funcs_p + 0x38))(_g_rw_init_sem,*(code **)(_r_osi_funcs_p + 0x38));
        break;
      case '\v':
        ble_txpwr_set_inter(*puStack_34,puStack_34[1],puStack_34[2]);
        break;
      case '\r':
        r_btdm_vnd_offload_process(uStack_37,puStack_34);
      }
      r_btdm_task_recycle(&cStack_38);
      bVar1 = true;
      btdm_rw_run(_LANCHOR5);
    }
    if (!bVar1) {
      btdm_rw_run(_LANCHOR5);
    }
  } while( true );
}

