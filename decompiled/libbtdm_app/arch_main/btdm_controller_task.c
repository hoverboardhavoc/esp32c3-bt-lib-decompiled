/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  int iVar1;
  bool bVar2;
  code *pcVar3;
  byte bStack_48;
  undefined1 uStack_47;
  undefined1 *puStack_44;
  
  s_btdm_state = 0;
  do {
    pcVar3 = *(code **)(_r_osi_funcs_p + 0x34);
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf8))(*(code **)(_r_plf_funcs_p + 0xf8));
    iVar1 = (*pcVar3)(*(undefined4 *)(iVar1 + 8),0xffffffff);
    if (iVar1 == 0) {
      return;
    }
    bVar2 = false;
    while( true ) {
      iVar1 = (**(code **)(_r_osi_funcs_p + 0x5c))
                        (_g_rw_schd_queue,&bStack_48,0,*(code **)(_r_osi_funcs_p + 0x5c));
      if (iVar1 != 1) break;
      if (bStack_48 == 0xb) {
        ble_txpwr_set_inter(*puStack_44,puStack_44[1],puStack_44[2]);
      }
      else if (bStack_48 < 0xc) {
        if (bStack_48 == 2) {
          (**(code **)(_r_ip_funcs_p + 0x4c))(*(code **)(_r_ip_funcs_p + 0x4c));
        }
        else if ((byte)(bStack_48 - 7) < 4) {
          if (bStack_48 == 9) {
            (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
            bt_bb_v2_init_cmplx(0);
            (**(code **)(_r_modules_funcs_p + 0x1ac))(*(code **)(_r_modules_funcs_p + 0x1ac));
            (**(code **)(_r_modules_funcs_p + 0x1b8))(*(code **)(_r_modules_funcs_p + 0x1b8));
            btdm_controller_on_reset();
            r_intc_enable();
            iVar1 = (**(code **)(_r_osi_funcs_p + 0xb4))
                              (&coex_schm_btdm_callback,*(code **)(_r_osi_funcs_p + 0xb4));
            if (iVar1 == 0) {
              btdm_vnd_offload_task_register(1,&coex_schm_process);
            }
            else if (1 < _g_bt_plf_log_level) {
              ets_printf("Coex register schm btdm cb faild\n");
            }
            s_btdm_state = 2;
          }
          else {
            if (bStack_48 == 10) {
              (**(code **)(_r_osi_funcs_p + 0xb4))(0,*(code **)(_r_osi_funcs_p + 0xb4));
              (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
              r_intc_disable();
              btdm_controller_on_reset();
              (**(code **)(_r_ip_funcs_p + 0x124))(2,*(code **)(_r_ip_funcs_p + 0x124));
            }
            else {
              if (bStack_48 == 8) {
                rw_stop();
                s_btdm_state = 0;
                goto _L325;
              }
              rw_pre_main();
            }
            s_btdm_state = 1;
          }
_L325:
          (**(code **)(_r_osi_funcs_p + 0x38))(_g_rw_init_sem,*(code **)(_r_osi_funcs_p + 0x38));
        }
      }
      else if (bStack_48 == 0xd) {
        (**(code **)(_r_plf_funcs_p + 0x114))
                  (uStack_47,puStack_44,*(code **)(_r_plf_funcs_p + 0x114));
      }
      (**(code **)(_r_plf_funcs_p + 0x30))(&bStack_48,*(code **)(_r_plf_funcs_p + 0x30));
      btdm_rw_run(s_btdm_state);
      bVar2 = true;
    }
    if (!bVar2) {
      btdm_rw_run(s_btdm_state);
    }
  } while( true );
}

