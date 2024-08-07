/*
 * Last changed at upstream commit ef1dfc518572e9cda55f13906e32207b40ee280b
 * https://github.com/espressif/esp32c3-bt-lib/commit/ef1dfc518572e9cda55f13906e32207b40ee280b
 * Upstream date: 2024-08-07 12:57:51 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(f583012)
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
  char cStack_38;
  undefined1 uStack_37;
  undefined1 *puStack_34;
  
  _LANCHOR6 = 0;
  do {
    pcVar3 = *(code **)(_r_osi_funcs_p + 0x34);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xf8))(*(code **)(_r_plf_funcs_p + 0xf8));
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
        (**(code **)(_r_ip_funcs_p + 0x4c))(*(code **)(_r_ip_funcs_p + 0x4c));
        break;
      case '\a':
      case '\b':
      case '\t':
      case '\n':
        if (cStack_38 == '\t') {
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
          _LANCHOR6 = 2;
        }
        else {
          if (cStack_38 == '\n') {
            (**(code **)(_r_osi_funcs_p + 0xb4))(0,*(code **)(_r_osi_funcs_p + 0xb4));
            (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
            r_intc_disable();
            btdm_controller_on_reset();
            (**(code **)(_r_ip_funcs_p + 0x124))(2,*(code **)(_r_ip_funcs_p + 0x124));
          }
          else {
            if (cStack_38 == '\b') {
              rw_stop();
              _LANCHOR6 = 0;
              goto _L311;
            }
            rw_pre_main();
          }
          _LANCHOR6 = 1;
        }
_L311:
        (**(code **)(_r_osi_funcs_p + 0x38))(_g_rw_init_sem,*(code **)(_r_osi_funcs_p + 0x38));
        break;
      case '\v':
        ble_txpwr_set_inter(*puStack_34,puStack_34[1],puStack_34[2]);
        break;
      case '\r':
        (**(code **)(_r_plf_funcs_p + 0x114))
                  (uStack_37,puStack_34,*(code **)(_r_plf_funcs_p + 0x114));
      }
      bVar1 = true;
      (**(code **)(_r_plf_funcs_p + 0x30))(&cStack_38,*(code **)(_r_plf_funcs_p + 0x30));
      btdm_rw_run(_LANCHOR6);
    }
    if (!bVar1) {
      btdm_rw_run(_LANCHOR6);
    }
  } while( true );
}

