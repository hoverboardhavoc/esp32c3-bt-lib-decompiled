/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  undefined4 uVar3;
  uint uVar4;
  code *pcVar5;
  byte bStack_38;
  undefined1 uStack_37;
  undefined1 *puStack_34;
  
  s_btdm_state = 0;
  while( true ) {
    pcVar5 = *(code **)(_r_osi_funcs_p + 0x34);
    iVar2 = r_btdm_vnd_ol_task_env_get();
    iVar2 = (*pcVar5)(*(undefined4 *)(iVar2 + 8),0xffffffff);
    if (iVar2 == 0) break;
    bVar1 = false;
    while (iVar2 = (**(code **)(_r_osi_funcs_p + 0x5c))
                             (_g_rw_schd_queue,&bStack_38,0,*(code **)(_r_osi_funcs_p + 0x5c)),
          iVar2 == 1) {
      if (bStack_38 == 0xb) {
        ble_txpwr_set_inter(*puStack_34,puStack_34[1],puStack_34[2]);
      }
      else if (bStack_38 < 0xc) {
        if (bStack_38 == 2) {
          r_hci_tl_hci_pkt_handler();
        }
        else if ((byte)(bStack_38 - 7) < 4) {
          if (bStack_38 == 9) {
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
            s_btdm_state = 2;
            (**(code **)(_r_osi_funcs_p + 0x38))(_g_rw_init_sem,*(code **)(_r_osi_funcs_p + 0x38));
            iVar2 = r_sdk_config_get_opts();
            uVar3 = 0x40e801ba;
            uVar4 = (uint)*(byte *)(iVar2 + 0xc) | s_btdm_state << 8;
          }
          else if (bStack_38 == 10) {
            (**(code **)(_r_osi_funcs_p + 0xb4))(0,*(code **)(_r_osi_funcs_p + 0xb4));
            r_sdk_config_get_opts();
            r_intc_disable();
            btdm_controller_on_reset();
            r_rwble_hw_disable(2);
            s_btdm_state = 1;
            (**(code **)(_r_osi_funcs_p + 0x38))(_g_rw_init_sem,*(code **)(_r_osi_funcs_p + 0x38));
            iVar2 = r_sdk_config_get_opts();
            uVar4 = (uint)*(byte *)(iVar2 + 0xc) | s_btdm_state << 8;
            uVar3 = 0x410801bb;
          }
          else if (bStack_38 == 8) {
            rw_stop();
            s_btdm_state = 0;
            (**(code **)(_r_osi_funcs_p + 0x38))(_g_rw_init_sem,*(code **)(_r_osi_funcs_p + 0x38));
            uVar3 = 0x40c801bd;
            uVar4 = s_btdm_state;
          }
          else {
            rw_pre_main();
            s_btdm_state = 1;
            (**(code **)(_r_osi_funcs_p + 0x38))(_g_rw_init_sem,*(code **)(_r_osi_funcs_p + 0x38));
            uVar3 = 0x40a801bc;
            uVar4 = s_btdm_state;
          }
          r_ble_log_internal_x1(uVar3,uVar4);
        }
      }
      else if (bStack_38 == 0xd) {
        r_btdm_vnd_offload_process(uStack_37,puStack_34);
      }
      r_btdm_task_recycle_hack(&bStack_38);
      bVar1 = true;
      btdm_rw_run(s_btdm_state);
    }
    if (!bVar1) {
      btdm_rw_run(s_btdm_state);
    }
  }
  return;
}

