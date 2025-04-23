/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_task
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
  byte bStack_38;
  undefined1 uStack_37;
  undefined1 *puStack_34;
  
  s_btdm_state = 0;
  do {
    pcVar3 = *(code **)(_r_osi_funcs_p + 0x34);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xf8))(*(code **)(_r_plf_funcs_p + 0xf8));
    iVar2 = (*pcVar3)(*(undefined4 *)(iVar2 + 8),0xffffffff);
    if (iVar2 == 0) {
      return;
    }
    bVar1 = false;
    while (iVar2 = (**(code **)(_r_osi_funcs_p + 0x5c))
                             (_g_rw_schd_queue,&bStack_38,0,*(code **)(_r_osi_funcs_p + 0x5c)),
          iVar2 == 1) {
      if (bStack_38 == 0xb) {
        ble_txpwr_set_inter(*puStack_34,puStack_34[1],puStack_34[2]);
      }
      else if (bStack_38 < 0xc) {
        if (bStack_38 == 2) {
          (**(code **)(_r_ip_funcs_p + 0x4c))(*(code **)(_r_ip_funcs_p + 0x4c));
        }
        else if ((byte)(bStack_38 - 7) < 4) {
          if (bStack_38 == 9) {
            (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
            bt_bb_v2_init_cmplx(0);
            (**(code **)(_r_modules_funcs_p + 0x1ac))(*(code **)(_r_modules_funcs_p + 0x1ac));
            (**(code **)(_r_modules_funcs_p + 0x1b8))(*(code **)(_r_modules_funcs_p + 0x1b8));
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
          }
          else {
            if (bStack_38 == 10) {
              (**(code **)(_r_osi_funcs_p + 0xb4))(0,*(code **)(_r_osi_funcs_p + 0xb4));
              (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
              r_intc_disable();
              btdm_controller_on_reset();
              (**(code **)(_r_ip_funcs_p + 0x124))(2,*(code **)(_r_ip_funcs_p + 0x124));
            }
            else {
              if (bStack_38 == 8) {
                rw_stop();
                s_btdm_state = 0;
                goto _L326;
              }
              rw_pre_main();
            }
            s_btdm_state = 1;
          }
_L326:
          (**(code **)(_r_osi_funcs_p + 0x38))(_g_rw_init_sem,*(code **)(_r_osi_funcs_p + 0x38));
        }
      }
      else if (bStack_38 == 0xd) {
        (**(code **)(_r_plf_funcs_p + 0x114))
                  (uStack_37,puStack_34,*(code **)(_r_plf_funcs_p + 0x114));
      }
      bVar1 = true;
      (**(code **)(_r_plf_funcs_p + 0x30))(&bStack_38,*(code **)(_r_plf_funcs_p + 0x30));
      btdm_rw_run(s_btdm_state);
    }
    if (!bVar1) {
      btdm_rw_run(s_btdm_state);
    }
  } while( true );
}

